//
//  main.cpp
//  The first exercise of Algorithm 1 course on Coursera
//  Disjoint-set data structure: Union-Find (Quick union method)
//  QuickUnionUF
//
//  Created by Elham Taghizadeh on 08/02/14.
//  Copyright (c) 2014 Elham Taghizadeh. All rights reserved.
//

#include <iostream>
using namespace std;

class QuickUnionUF
{
public:
    QuickUnionUF(int N){
        Number = N;
        id = new int(N);
        for(int i=0; i<N;i++)
        {
            id[i]=i;
        }
    }
    void Union(int p, int q)
    {
        int rp = root(p);
        int rq = root(q);
        id[rp] = rq;
        
    }
    bool find(int p, int q)
    {
        return root(p)==root(q);
    }
    void show()
    {
        for (int i =0;i<Number;i++)
        {
            cout << id[i] << ' ';
        }
        cout<<endl;
    }
private:
    int Number;
    int *id;
    int root(int p){
        while(id[p]!=p)p = id[p];
        return p;
    }
};

int main(int argc, const char * argv[])
{
    int N, p, q;
    char command;
    cout << "Please enter the number of nodes: ";
    cin >> N;
    QuickUnionUF UF(N);
    cout << "Union(p, q):  \'u\' p q" << endl ;
    cout << "Connected (p, q): \'c\' p q" << endl;
    cout << "Show: \'s\' p q" << endl;
    cout << "end: \'e\' p q" << endl;
    
    while(1)
    {
        cin >> command >> p >> q;
        switch (command) {
            case 'u':
                if (p>=N or q>=N){
                    cout<<"\'p\' or \'q\' out of range."<<endl;
                    break;
                }
                UF.Union(p, q);
                break;
            case 'c':
                if (p>=N or q>=N) {cout<<"\'p\' or \'q\' out of range."<<endl; break;}
                cout << UF.find(p, q) << endl;
                break;
            case 's':
                UF.show();
                break;
            case 'e':
                return 0;
            default:
                break;
        }
    }
    UF.show();
    return 0;
    // insert code here...
    
}

