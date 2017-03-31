#include<stdio.h>
#include<conio.h>
#include<iostream.h>
struct node
{
  int coef,expon;
  node *link;
};
//___________________________*******************_______________________________
class polynomial
{
  public:
               polynomial();
          polynomial Add( polynomial d);
          polynomial mult(polynomial d);
          void mult(int  n);
          void revers();
          void WriteInOut(FILE *ft);
	  void insert(int x,int y);
	       ~polynomial();
  private:
          node *start;
	  node *revers(node *p);
};
//___________________________******************_______________________________
polynomial::polynomial()
 {
  start=0;
 }
//____________________________*****************________________________________
void polynomial::insert(int x,int y)
{
 node *n,*p,*q;
 n=new node;
 if(!n){
        cout<<"can not allocate memory";
        return;
       }
 n->coef =x;
 n->expon=y;
 if(!start || x>start->expon){
                              n->link=start;
                              start=n;
                              return;
                             }
 q=start;
 p=start->link;
 while(p && x>(p->expon))
                       {
                        p=p->link;
                        q=q->link;
                       }
if(x==p->expon){
		 p->coef=(p->coef)+y;
                 delete n;
                }
n->link=p;
q->link=n;
}
//______________________________*******************____________________________
polynomial polynomial::Add(polynomial d)
{
 polynomial c;
 node *p=start,*q=d.start;
 c.start=new node;
 while(p && q)
              {
	       if((p->expon)>(q->expon))
				       {
                                        c.insert(p->coef,p->expon);
                                        p=p->link;
                                       }
	       if((p->expon)<(q->expon)){
                                        c.insert(q->coef,q->expon);
                                        q=q->link;
                                       }
               if(p->expon ==q->expon){
                                        c.insert(p->coef+q->coef,p->expon);
                                        p=p->link;
                                        q=q->link;
                                       }
              }
 while(p)
         {
          c.insert(p->coef,p->expon);
          p=p->link;
         }
 while(q)
         {
          c.insert(q->coef,q->expon);
          q=q->link;
         }
 return c;
}
//__________________________*******************______________________________
polynomial polynomial::mult(polynomial d)
{
 polynomial c;
 node *p=start,*q=d.start;
 c.start=new node;
 for(;p;p=p->link)
    for(;q;q=q->link)
       c.insert((q->coef)*(p->coef),(q->expon)+(p->expon));
 return c;
}
//__________________________*******************________________________________
void polynomial::mult(int n)
{
 node *p=start;
 for(;p;p=p->link)
    p->coef*=n;
}
//___________________________*******************_______________________________
node *polynomial::revers(node *p)
{
 node *q;
 if(!(p->link))
               {
                start=p;
                return p;
               }
 q=revers(p->link);
 q->link=p;
 return p;
}
//___________________________*******************_______________________________
void polynomial::revers()
{
 node *n=start;
 revers(n);
}
//___________________________******************_________________________________
void polynomial::WriteInOut(FILE *ft)
{
 node *p=start;
 while(p->link!=0)
		{
		 fprintf(ft,"  %i",p->coef,"%sx^","%i",p->expon);
		 cout<<(p->coef)<<"x^"<<(p->expon)<<"  ";
		 p=p->link;
		}
 cout<<"/n";
 fprintf(ft,"%s /n");
}
//___________________________*****************_________________________________
polynomial::~polynomial()
{
    node *p=start,*q=start->link;
    while(p)
	    {
	      delete p;
	      p=q;
	      q=q->link;
	    }
}
//___________________________*****************__________________________________
void main()
{
 FILE *fp,*ft;
 polynomial a,b,c;
 int i,x,y,z;
 fp=fopen("polynomial.in" ,"rt");
 ft=fopen("polynomial.out","wt");
 fscanf(fp,"%d",&z);
 for(i=0;i<=z;i++)
		  {
                   fscanf(fp,"%d",&x,"%d",&y);
                   a.insert(x,y);
                  }
 fscanf(fp,"%d",&z);
 for(i=0;i<=z;i++)
		  {
                   fscanf(fp,"%d",&x,"d",&y);
                   b.insert(x,y);
		  }
 c=a.Add(b);
 fprintf(ft,"%s A+B= ");
 cout<<" A+B= ";
 c.WriteInOut(ft);
 c=a.mult(b);
 fprintf(ft,"%s A*B= ");
 cout<<" A*B= ";
 c.WriteInOut(ft);
 a.revers();
 fprintf(ft,"%s A= ");
 cout<<" A= ";
 c.WriteInOut(ft);
 b.mult(5);
 fprintf(ft,"%s 5*B= ");
 cout<<" 5*B= ";
 c.WriteInOut(ft);
}
