#include <bits/stdc++.h>
using namespace std;

#define mem(a,n) memset(a,n,sizeof(a))
#define memc(a,b) memcpy(a,b,sizeof(b))
#define rep(i,a,n) for(int i=a;i<n;i++) ///[a,n)
#define pb push_back
#define IO ios::sync_with_stdio(false)
#define fre freopen("in.txt","r",stdin)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
typedef unsigned long long ull;
const double PI=acos(-1.0);
const double E=2.718281828459045;
const double eps=1e-3;
const int INF=0x3f3f3f3f;
const int MOD=1e8+7;
const int N=1e4+5;
const ll maxn=1e6+5;
const int dir[4][2]= {-1,0,1,0,0,-1,0,1};
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        ll ans=0;
        if(!k) ans-=n;
        rep(p,k+1,n+1)
        {
            ans=ans+(n/p)*(p-k);
            int t=n%p+1-k;
            if(t>0) ans+=t;///样例1
        }
        cout<<ans<<endl;
    }
    return 0;
}
