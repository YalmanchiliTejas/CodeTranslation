#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
int n,B[100005],a[100005],len;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    B[1]=-a[1],len=1;
    for(int i=2;i<=n;i++)
    {
        if(-a[i]>=B[len]) B[++len]=-a[i];
        else
        {
            int pos=upper_bound(B+1,B+len,-a[i])-B;
            B[pos]=-a[i];
        }
    }
    cout<<len<<endl;
}