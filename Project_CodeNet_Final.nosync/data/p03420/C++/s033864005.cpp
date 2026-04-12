//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define ll long long
#define mod 1000000007
#define C 0.5772156649
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
#define pil pair<int,ll>
#define pii pair<int,int>
#define ull unsigned long long
#define base 1000000000000000000
#define fio ios::sync_with_stdio(false);cin.tie(0)

using namespace std;

const double g=10.0,eps=1e-12;
const int N=100000+10,maxn=100000+10,inf=0x3f3f3f3f,INF=0x3f3f3f3f3f3f3f3f;


int main()
{
    ll n,k,ans=0;
    scanf("%lld%lld",&n,&k);
    if(k==0)
    {
        printf("%lld\n",n*n);
        return 0;
    }
    for(int i=k;i<=n;i++)
    {
        ans+=n-i;
        for(int j=i;j<=n;j+=i)
        {
            if(j+i<=n)ans+=i-k;
            else ans+=max(n-j-k+1,0ll);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/********************

********************/
