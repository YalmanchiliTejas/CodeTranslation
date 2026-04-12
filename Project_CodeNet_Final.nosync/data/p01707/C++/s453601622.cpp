#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define show(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define show(x)
#endif

typedef long long int ll;
typedef pair<int,int> pii;
template<typename T> using vec=std::vector<T>;

const int inf=1<<30;
const long long int infll=1LL<<62;
const double eps=1e-9;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

const ll mod=1e9+7;
ll inv[2001];

ll extgcd(ll a,ll b,ll &x,ll &y){
	ll d=a;
	if(b!=0){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	} else {
		x=1; y=0;
	}
	return d;
}

void solve(const ll n,const ll d,const ll x){
    static ll dp[2001][2001];
    fill_n((ll*)dp,2001*2001,0);
    rep(i,1,x) dp[1][i]=1;
    rep(i,2,n+1) rep(j,1,n+1){
        dp[i][j]=dp[i][j-1];
        if(j-x>=0) dp[i][j]=(dp[i][j]-dp[i-1][j-x]+mod)%mod;
        dp[i][j]=(dp[i][j]+dp[i-1][j-1]+mod)%mod;
    }

    ll ans=0;
    rep(i,1,min(d,n)+1){
        ll tmp=dp[i][n];
        rep(j,0,i){
            tmp=(d-j)%mod*tmp%mod;
            tmp=tmp*inv[i-j]%mod;
        }
        ans=(ans+tmp)%mod;
    }
    cout << ans << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);

    inv[1]=1;
    rep(i,2,2001){
        ll k;
        extgcd(i,mod,inv[i],k);
        inv[i]=(inv[i]+mod)%mod;
    }
    while(true){
        ll n,d,x;
        cin >> n >> d >> x;
        if(n==0 and d==0 and x==0) break;
        solve(n,d,x);
    }
    return 0;
}