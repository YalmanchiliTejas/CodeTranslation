#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int n,m,k;

struct mod_fac{
    private:
        vector<ll> f,i_f;
        int n;ll MOD;
    public:
        void init(int n,ll m){
            MOD=m;
            f.resize(n+1,0);
            i_f.resize(n+1,0);
            f[0]=1;
            rep(i,n){
                f[i+1]=f[i]*(i+1)%MOD;
            }
            i_f[n]=power(f[n],MOD-2);
            per(i,n){
                i_f[i]=(i_f[i+1]*(i+1))%MOD;
            }
        }
        ll power(ll a ,ll x){
            if (x==0) return 1;
            if (x==1) return a%MOD;
            if (x==2) return (a*a)%MOD;
            if (x%2==1) return (a*power(power(a,(x-1)/2),2))%MOD;
            return (power(power(a,x/2),2))%MOD;
        }
        ll fac(int x){
            return f[x];
        }
        ll invfac(int x){
            return i_f[x];
        }
        ll comb(int m,int k){
            if (m<0 or k<0) return 0;
            if (m<k) return 0;
            return (((f[m]*i_f[k])%MOD)*i_f[m-k])%MOD;
        }
};
ll ans=0;
int main(){
    cin >> n >> m >> k;
    mod_fac M;M.init(n*m,mod);
    rep(d,n){
        (ans+=d%mod*(n-d)%mod*m%mod*m%mod*M.comb(n*m-2,k-2)%mod) %= mod;
    }
    rep(d,m){
        (ans+=d%mod*(m-d)%mod*n%mod*n%mod*M.comb(n*m-2,k-2)%mod) %= mod;
    }
    cout << ans%mod << endl;
}