//
//  main.cpp
// The first exercise of Algorithm 1 course on coursera:
//  Disjoint-set data structure: Union-Find (Quick find method)
//  QuickFindUF
//
//  Created by Elham Taghizadeh on 08/02/14.
//  Copyright (c) 2014 Elham Taghizadeh. All rights reserved.
//

#include <iostream>

using namespace std;
class QuickFindUF
{
public:
    QuickFindUF(int N)
    {
        id = new int[N];
        Number = N;
        for(int i=0;i<N;i++)
        {
            id[i] = i;
        }
    }
    bool find(int p, int q)
    {
        return (id[p]==id[q]);
    }
    void Union(int p, int q)
    {
        int pid = id [p];
        int qid = id [q];
        if (pid==qid) {
            return;
        }
        for (int i=0; i < Number; i++) {
            if (id[i]==pid) {
                id[i] = qid;
            }
        }
    }
    void show()
    {
        for (int i=0; i<Number; i++)
        {
            cout << id[i] << ' ';
        }
        cout << endl;
    }
private:
    int *id;
    int Number;
};

int main(int argc, const char * argv[])
{
    int N, p, q;
    char command;
    cout << "Please enter the number of nodes: ";
    cin >> N;
    QuickFindUF UF(N);
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
}

