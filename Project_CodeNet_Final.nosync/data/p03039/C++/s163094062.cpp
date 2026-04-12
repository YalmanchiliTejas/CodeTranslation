#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define USE_LLONG_AS_INT
#ifdef USE_LLONG_AS_INT
#define int long long
#define inf (1ll<<60)
#else
#define inf (1<<30)
#endif
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,n) for(int i=(n)-1;i>=0;i--)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pb push_back
#define pi pair<int,int>
#define vp vector<pair<int,int>>
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define MEMSET(a) memset(a,0,sizeof(a))
#define Yes(f) cout<<(f?"Yes":"No")<<endl
#define yes(f) cout<<(f?"yes":"no")<<endl
#define YES(f) cout<<(f?"YES":"NO")<<endl
#define SORT(v) sort(all(v))
#define RSORT(v) sort(all(v), greater<int>())

using namespace std;

const int mod=1e9+7;
const string sp=" ";

void run();

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
}

signed main(){
    init();
    run();
    return 0;
}

class Combination {
    private:
    vector<int> x, y;
    
    int modpow(int x, int n, int mod = (int)1e9 + 7) {
        int ret = 1;
        while (n > 0) {
            if ((n & 1)) {
                ret = ret * x % mod;
            }
            x = x * x % mod;
            n >>= 1;
        }
        return ret;
    }
    
    public:
    Combination(int n) {
        x.resize(n+1);
        y.resize(n+1);        
        x[0]=y[0]=1;
        for (int i = 1; i <= n; i++) {
            x[i]=(x[i-1]*i)%mod;
            y[i]=modpow(x[i],mod-2);
        }
    }
    
    int get(int n, int r) {
        if (n < r) return 0;
        return x[n] * y[n - r] % mod * y[r] % mod;
    }
    
};

void run(){
    int n,m,k;
    cin>>n>>m>>k;
    Combination comb(n*m);
 int ans=0;
rep(i,n)ans=(ans+i*(n-i)%mod*m%mod*m%mod)%mod;
rep(i,m)ans=(ans+i*(m-i)%mod*n%mod*n%mod)%mod;
ans=ans*comb.get(n*m-2,k-2)%mod;
cout<<ans<<endl;
}