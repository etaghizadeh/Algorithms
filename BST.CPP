#include<iostream.h>
#include<stdio.h>
#include<conio.h>

 class node
 {   private:
	     int data;
	     node * lchild;
	     node * rchild;
     friend class bst;
 };

 class bst
 {  private:
	   node * root;
	   node * search( int);

    public:
	 bst();
	 int addition( const int);
	 void delet( int);
	 node * search1(const int);
	 void preorder(node *);
	 node * show();

    friend void preorder();

 };
//*********************************************************************
 bst::bst()
 {
    root=0;
    return;
 }
//**********************************************************************
 void bst::preorder(node * p)
 {
     if(p)
     {  cout<<" "<<p->data;
	if (p->lchild) cout<<"(";
	preorder(p->lchild);
	preorder(p->rchild);
	cout<<")";
     }

  }
//**********************************************************************
 node * bst::search(int m)
 {
      node *q=root;
      for(node *p=root;p;)
      {  if(m==p->data) return q;
	 if(m<p->data) { q=p;p=p->lchild; }
	 if(m>p->data) { q=p;p=p->rchild; }
       }
       return 0;
 }
//**************************************************************************
 void bst::delet(int m)
 {  node *q,*p,*t;

    p=search1(m);
    if(!p) return;
    t=p;

    while (!(p->lchild==0 && p->rchild==0))
    {
       if(p->lchild)
       {   p=p->lchild;
	   while(p->rchild)
	   p=p->rchild;
	   t->data=p->data;
	   t=p;
	}
	else if(p->rchild)
	      {   p=p->rchild;
		  while(p->lchild)
		  p=p->lchild;
		  t->data=p->data;
		   t=p;
	      }
    }

    q=search(p->data);
    if(p==q->lchild)
       q->lchild=0;
    if(p==q->rchild)
       q->rchild=0;
    t->data=p->data;
    t=p;
 }


//*************************************************************************
 int bst::addition( const int m)
 {
     node * p=root;
     node * p1=0;

     while(p)
     {   p1=p;
	 if(m==p->data) return 0;
	 if(m<p->data) p=p->lchild;
	 else p=p->rchild;
      }

      p=new node;
      if (!p) {
	 cout<<"no space to get.";
	 return 0;
      }
      p->lchild=0;
      p->rchild=0;
      p->data=m;
      if (!root) root=p;
      else if (m<p1->data) p1->lchild=p;
      else p1->rchild=p;
      return 1;
 }
//***********************************************************************
 node * bst::search1(const int m)
 {
      for (node * p=root;p;)
      {   if(m==p->data) return p;
	  if(m<p->data) p=p->lchild;
	  else p=p->rchild;
      }
      return 0;
 }

//********************************************************************
 node * bst::show()
 { return root;
 }
//***********************************************************************

 void main()
 {
    FILE * fp;
    int m,n;
    bst b;
    char ch;



    cout<<"\n to aad a new digit to the bst tree press (a) ";
    cout<<"\n to search a specific number press (s) ";
    //cout<<"\n to delete a number press (d)";
    cout<<"\n to see the tree press (h)";
    cout<<"\n to quit the program press (q)\n";

    while ( 1 )
    {  ch=getch();
       if( ch=='q' ){
	 cout<<"\nthe program has been ended.";
	 return;
       }
    switch (ch)
    {   case 'a': cout<<"\ninsert a number to add to the bst.\n";
		  cin>>n;
		  m=b.addition(n);
		  if(m==1) cout<<"\nnumber has been added.";
		  else cout<<"\nnumber has exist.";
		  break;

	 case 's':cout<<"\ninsert the number u want to search\n";
		  cin>>n;
		  node *t=0;
		  t=b.search1(n);
		  if (t) cout<<"this digit is finded.";
		  else cout<<"this number is not in the list.";
		  break;

	 //case 'd':cout<<"\nenter digit should be removed.\n";
		  //cin>>n;
		  //b.delet(n);
		  //break;

	 case 'h':cout<<"\nthe bst :\n";
		  node *t1=b.show();
		  b.preorder(t1);
		  break;

      }
  }
 }