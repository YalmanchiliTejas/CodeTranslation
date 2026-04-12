#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define shalaby ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);cerr.tie(0);
///#define mod 1e9+7
using namespace std;

inline int D()
{
    int t;
    scanf("%d",&t);
    return t;
}
inline ll llD()
{
    ll t;
    scanf("%lld",&t);
    return t;
}
 ll mod=1e9+7;
const int OO=-1e6;
int xt[4]= {1,0,0,-1};
int yt[4]= {0,1,-1,0};
////////////////////////////////////////////////////////////////////////////////////

ll mem[100005][3],a[200005],b[105],n,m,k;
bool valid(int x,int y)
{
    return x>-1 && y>-1 && x<n && y<m;
}
void init()
{
    memset(mem,-1,sizeof mem);
}

/////////////////////////////////////////////////////////////////////




int main()
{
    init();
    int T=1;
///   T=D();
    while(T-->0)
    {

        cin>>n;
        ll sum=0,ans=0,k;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        for(int i=0;i<n-2;i++)
        {
            sum-=a[i];
            k=((sum%mod)*(a[i]%mod))%mod;
            k%=mod;
            ans%=mod;
            ans+=k;
            ans%=mod;
        }
        k=((a[n-1]%mod)*(a[n-2]%mod))%mod;
         k%=mod;
            ans%=mod;
            ans+=k;
            ans%=mod;



cout<<ans;
    }
}
