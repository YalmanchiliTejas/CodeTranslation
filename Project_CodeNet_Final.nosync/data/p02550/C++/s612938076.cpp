#include <bits/stdc++.h>
#define ft first
#define sd second
#define maxn 200005
#define mod 998244353
#define PI 3.14159265
#define MP make_pair
#define PB push_back
#define heap priority_queue
#define Bjerg ""
using namespace std;
long long n;
int a[maxn], m;
int av[maxn];
void read()
{
    cin >> n >> a[0] >> m;
}
long long sum[maxn];
long long get(int l , int r)
{
    if(r<l) return 0;
    if(r<0) return 0;
    long long res=sum[r];
    if(l>0) res-=sum[l-1];
    return res;
}
void solve()
{
    if(n<=1e5)
    {
        long long res= a[0];
        for(int i=1;i<n;++i)
        {
            a[i]= (1ll*a[i-1]*a[i-1])%m;
            res+=a[i];
        }
        cout << res<<endl;
    }
    else
    {
        memset(av,-1,sizeof(av));
        av[a[0]]=0;
        sum[0]=a[0];
        int l , r ;
        for(int i=1;i<n;++i)
        {
            a[i]= (1ll*a[i-1]*a[i-1])%m;
            if(av[a[i]]!=-1)
            {
                r=i-1;
                l=av[a[i]];
                break;
            }
            av[a[i]]=i;
            sum[i] = sum[i-1]+a[i];
        }
        long long res= get(0,l-1);
        n-=l;
        int dis = (r-l+1);
        res += 1ll*get(l,r)*(n/dis);
        res += get(l+0,l+n%dis-1);
        cout << res;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(Bjerg".inp","r",stdin);
    read();
    solve();
    return 0;
}
