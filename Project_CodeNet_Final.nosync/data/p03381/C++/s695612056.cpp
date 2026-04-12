#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
int oldx[200050];
struct node
{
        int num;
        int i;
};
int cmp (node a, node b)
{
        return (a.num>b.num);
}
int main ()
{
        int N,l;
        node x[200050];

        while(cin>>N)
        {
                l=N/2;
                for(int i=1;i<=N;i++)
                {
                        scanf("%d",&x[i].num);
                        oldx[i]=x[i].num;
                        x[i].i=i;
                }
                sort(x+1,x+N+1,cmp);
//                for(int i=1;i<=N;i++)
//                {
//                        cout<<x[i].num<<" "<<x[i].i<<endl;
//                }
                for(int i=1;i<=N;i++)
                {


                        if(oldx[i]<x[l].num && x[l].i != i)
                        {
                                cout<<x[l].num<<endl;
                        }
                        else
                        {
                                cout<<x[l+1].num<<endl;
                        }
                }

        }

}
