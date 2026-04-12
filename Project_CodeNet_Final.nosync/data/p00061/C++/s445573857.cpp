#include<iostream>
#include<ios>
using namespace std;
int p[101];
main()
{
    int P,S;
    while(scanf("%d,%d",&P,&S),P)
    {
        p[P]=S;
    }
    while(cin>>P)
    {
        int cnt=1;
        bool is[99]={};
        for(int i=0;i<=100;i++)
        {
            if(!is[p[i]])
            {
                is[p[i]]=1;
                cnt+=p[i]>p[P];
            }
        }
        cout<<cnt<<endl;
    }
}
