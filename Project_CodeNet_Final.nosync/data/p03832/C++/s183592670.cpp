#include<bits/stdc++.h>
#define rep(i,a,...) for(int i = (a)*(strlen(#__VA_ARGS__)!=0);i<(int)(strlen(#__VA_ARGS__)?__VA_ARGS__:(a));++i)
#define per(i,a,...) for(int i = (strlen(#__VA_ARGS__)?__VA_ARGS__:(a))-1;i>=(int)(strlen(#__VA_ARGS__)?(a):0);--i)
#define foreach(i, n) for(auto &i:(n))
#define all(x) (x).begin(), (x).end()
#define bit(x) (1ll << (x))
#define lambda(RES_TYPE, ...) (function<RES_TYPE(__VA_ARGS__)>)[&](__VA_ARGS__) -> RES_TYPE
#define method(FUNC_NAME, RES_TYPE, ...) function<RES_TYPE(__VA_ARGS__)> FUNC_NAME = lambda(RES_TYPE, __VA_ARGS__)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const ll MOD = (ll)1e9+7;
//const ll MOD = 998244353;
const int INF = (ll)1e9+7;
const ll INFLL = (ll)1e18;
template<class t>
using vvector = vector<vector<t>>;
template<class t>
using vvvector = vector<vector<vector<t>>>;
template<class t>
using priority_queuer = priority_queue<t, vector<t>, greater<t>>;
template<class t, class u> bool chmax(t &a, u b){if(a<b){a=b;return true;}return false;}
template<class t, class u> bool chmin(t &a, u b){if(a>b){a=b;return true;}return false;}
#ifdef DEBUG
#define debug(x) cout<<"LINE "<<__LINE__<<": "<<#x<<" = "<<x<<endl;
#else
#define debug(x) (void)0
#endif

namespace templates{
  ll modpow(ll x, ll b){
    ll res = 1;
    while(b){
      if(b&1)res = res * x % MOD;
      x = x * x % MOD;
      b>>=1;
    }
    return res;
  }

  ll modinv(ll x){
    return modpow(x, MOD-2);
  }

  bool was_output = false;
  template<class t>
  void output(t a){
    if(was_output)cout << " ";
    cout << a;
    was_output = true;
  }
  void outendl(){
    was_output = false;
    cout << endl;
  }
  ll in(){
    ll res;
    scanf("%lld", &res);
    return res;
  }

  template<class t>
  istream& operator>>(istream&is, vector<t>&x){
    for(auto &i:x)is >> i;
    return is;
  }

  template<class t, class u>
  istream& operator>>(istream&is, pair<t, u>&x){
    is >> x.first >> x.second;
    return is;
  }

  template<class t>
  void in(t&x){
    cin >> x;
  }

  template<class t>
  t in(){
    t res; cin >> res; return res;
  }

  template<class t>
  void out(t x){
    cout << x;
  }

  template<class t>
  vector<t> sorted(vector<t> line,function<bool(t,t)> comp=[](t a,t b){return a<b;}){
    sort(line.begin(),line.end(),comp);
    return line;
  }

  template<class t>
  vector<t> reversed(vector<t> line){
    reverse(line.begin(),line.end());
    return line;
  }
}

using namespace templates;

template<long long mod>
class modint{
	public:
		long long x;
		modint(long long a){x=a%mod;if(x<0)x+=mod;}
		modint(){x=0;}

		modint pow(long long a){
			modint res(1), b(x);
			while(a){
				if(a&1)res*=b;
				b*=b;
				a>>=1;
			}
			return res;
		}

		modint inv(){return pow(mod-2);}

		modint& operator+=(modint a){x=(x+a.x)%mod;return *this;}
		modint& operator-=(modint a){x=x-a.x;if(x<0)x+=mod;return *this;}
		modint& operator*=(modint a){x=x*a.x%mod;return *this;}
		modint& operator/=(modint a){x=x*a.inv().x%mod;return *this;}

		modint operator+(modint a){return modint(x)+=a;}
		modint operator-(modint a){return modint(x)-=a;}
		modint operator*(modint a){return modint(x)*=a;}
		modint operator/(modint a){return modint(x)/=a;}

		modint operator-(){return modint(x);}

		bool operator==(const modint a){return x == a.x;}
		bool operator<(const modint a){return x < a.x;}
		bool operator>(const modint a){return x > a.x;}
};

template<long long mod>
ostream& operator<<(ostream& os, const modint<mod>& a){
	os << a.x;
	return os;
}

using mint = modint<MOD>;

mint factorial(int x){
    if(x<=1)return 1;
    static vector<mint> dp(1e4);
    static vector<bool> used(1e4);
    mint &it = dp[x];
    if(used[x])return it;
    used[x] = true;
    return it = factorial(x-1) * x;
}

mint factorial_inv(int x){
    static vector<mint> dp(1e4);
    static vector<bool> used(1e4);
    if(used[x])return dp[x];
    used[x] = true;
    return dp[x] = factorial(x).inv();
}

mint combination(int a,int b){
    return factorial(a) * factorial_inv(b) * factorial_inv(a-b);
}


mint func(){
    int n = in();
    int a = in();
    int b = in();
    int c = in();
    int d = in();
    vvector<mint> dp(b+1,vector<mint>(n+1,0));
    dp[0][0] = 1;

    rep(i,1,b+1){
        rep(j,n+1){
            dp[i][j] += dp[i-1][j];
            if(i<a)continue;
            for(int k=c;k<=d and k*i<=j;++k){
                dp[i][j] += dp[i-1][j-i*k] * combination(n-j+i*k,i*k) * factorial(i*k) * (factorial_inv(i).pow(k)) * factorial_inv(k);
            }
        }
    }
    return dp[b][n];
}
int main(){

    cout << func() << endl;
  return 0;
}
