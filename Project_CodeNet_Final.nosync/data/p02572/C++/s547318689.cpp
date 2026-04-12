#define    ll           long long
#define    dn           double
#define    mp           make_pair
#define    pb           push_back
#define    se           second
#define    fi           first
#define    mod          1000000007
#define    sob(v)       v.begin(),v.end()
#define    sobr(v)      v.rbegin(),v.rend()
#define    fr(i,a,b)    for(int i=a;i<=b;++i)
#define    frr(i,a,b)   for(int i=a;i>=b;--i)
#define    pi           acos(-1.00)
#define    check        cout<<"*"<<endl
#define    ffix(x)      cout<<fixed<<setprecision(x)
#define    fast         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

#include<bits/stdc++.h>
#include<string.h>
using namespace std;

typedef vector<int> vi;
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef pair<int,vi> pp;

int dr[8]= {0,0,-1,1,-1,-1,+1,+1};
int dc[8]= {-1,1,0,0,-1,+1,-1,+1};

const int N=1000005;

inline void normal(ll &a){if(a>mod) a%=mod; (a<0) && (a+=mod);}
inline ll mod_mul(ll a,ll b){normal(a),normal(b); return (a*b)%mod;}
inline ll mod_add(ll a,ll b){normal(a),normal(b); return (a+b)%mod;}
inline ll mod_sub(ll a,ll b){normal(a),normal(b); a-=b; normal(a); return a;}
inline ll mod_pow(ll a,ll b){ll r=1; while(b>0){if(b&1)r=mod_mul(r,a); a=mod_mul(a,a); b>>=1;} return r;}
inline ll mod_inverse(ll a){return mod_pow(a,mod-2);}
inline ll mod_div(ll a,ll b){return mod_mul(a,mod_inverse(b));}

int main()
{
    int n;
    cin>>n;
    ll a[n+1];
    fr(i,1,n)cin>>a[i];
    ll pre[n+1],ans=0;
    pre[n]=a[n];
    frr(i,n-1,1)
    {
        pre[i]=(pre[i+1]+a[i])%mod;
        ans=(ans+a[i]*pre[i+1]%mod)%mod;
    }
    cout<<ans<<endl;
}
