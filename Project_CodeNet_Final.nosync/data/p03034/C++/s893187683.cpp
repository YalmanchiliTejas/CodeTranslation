#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,a[N];
ll pre[322][N],bk[322][N];
set<int>s;
void solve()
{
    ll ans=0;
    for(int x=1;x<n;x++)
        for(int y=1;y<x;y++)
    {
        ll res=0;
        if((n-1-x)%(x-y)!=0) continue;
        for(int k=x;k<n;k+=x-y)
            res+=a[k],s.insert(k);
        for(int k=n-1-x;k>=0;k-=x-y)
        {
            if(s.count(k)) {res=0;break;}
            res+=a[k];
        }
        s.clear();
        ans=max(ans,res);
    }
    printf("%lld\n",ans);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    if(n<500) {solve();return 0;}
    ll ans=0;
    int t=sqrt(n);
    for(int i=1;i<=t;i++)
    {
        for(int j=i;j<n;j+=i)
            pre[i][j]=a[j];
        for(int j=i;j<n;j++)
            pre[i][j]+=pre[i][j-1];
        for(int j=n-1-i;j>=0;j-=i)
            bk[i][j]=a[j];
        for(int j=n-1-i;j>=0;j--)
            bk[i][j]+=bk[i][j+1];
    }
    for(int i=1;i<n;i++)
    {
        int x=i,y=n-1-i,s=y-x;
        if(s<0)
        {
            int l=1,r=1;
            while(l<=y)
            {
                if(y%l==0)
                {
                    ll res=0;
                    if(l<=t)
                        res=bk[l][i]+pre[l][n-1-i];
                    else
                    {
                        for(int j=i;j<n;j+=l)
                            res+=a[j];
                        for(int j=n-1-i;j<n;j+=l)
                            res+=a[j];
                    }
                    ans=max(ans,res);
                }
                l=r+1;
                if(l>y) break;
                r=y/(y/l);
            }
        }
        else if(s>0)
        {
            int l=1,r=1;
            while(l<=y)
            {
                if(y%l==0&&s%l!=0)
                {
                    ll res=0;
                    if(l<=t)
                        res=bk[l][i]+pre[l][n-1-i];
                    else
                    {
                        for(int j=i;j<n;j+=l)
                            res+=a[j];
                        for(int j=n-1-i;j<n;j+=l)
                            res+=a[j];
                    }
                    ans=max(ans,res);
                }
                l=r+1;
                if(l>y) break;
                r=y/(y/l);
            }
        }
    }
    printf("%lld\n",ans);
}
/*
a=6,b=4
11
0 -4 0 -99 31 14 -15 -39 43 18 0
*/
