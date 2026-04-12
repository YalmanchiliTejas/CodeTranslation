#include <bits/stdc++.h>
#define fup(i,a,b) for(int i=a;i<=b;++i)
#define fdw(i,a,b) for(int i=a;i>=b;--i)
#define sync ios::sync_with_stdio(false);cin.tie(0)
#define cl(a) memset(a,0,sizeof(a))
#define gcd __gcd
#define fi first
#define se second
#define pb push_back
#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
//ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//ll ksm(ll a,ll b,ll mod){ll res=1;a%=mod;for(;b;b>>=1){if(b&1) res=res*a%mod;a=a*a%mod;}return res;}
//ll oula(ll n){ ll res=n;for(ll i=2;i*i<=n;i++){if(n%i==0){ res=res-res/i;while(n%i==0) n/=i;}}if(n>1) res=res-res/n;return res;}
//bool MRT(ll x){if(x==2)return true;fup(i,1,50){ll now=rand()%(x-2)+2;if(ksm(now,x-1,x)!=1)return false;}return true;}
//void shai(int n)fup(i,2,n){if(isprime[i]){v.push_back(i);for(int j=2*i;j<=10000;j+=i)isprime[j]=0;}}//"埃氏筛筛选素数"
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const double eps=1e-7;
const int N=4e5+10;
int main()
{

    sync;
    string s;
    cin>>s;
    int t1=0,t2=0;
    fup(i,0,2)
    {
        if(s[i]=='A')
            t1++;
        else t2++;
    }
    if(t1&&t2)
    {
        cout<<"Yes"<<endl;
    }else cout<<"No"<<endl;
    return 0;
}