#include<bits/stdc++.h>
#define rep(i,a,...) for(int i = (a)*(strlen(#__VA_ARGS__)!=0);i<(int)(strlen(#__VA_ARGS__)?__VA_ARGS__:(a));++i)
#define per(i,a,...) for(int i = (strlen(#__VA_ARGS__)?__VA_ARGS__:(a))-1;i>=(int)(strlen(#__VA_ARGS__)?(a):0);--i)
#define foreach(i, n) for(auto &i:(n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define bit(x) (1ll << (x))
using ll = long long;
//const ll MOD = (ll)1e9+7;
const ll MOD = 998244353;
const int INF = (ll)1e9+7;
const ll INFLL = (ll)1e18;
using namespace std;
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
void out(t x){
  cout << x;
}

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

ll n;
ll s;
vector<ll> line;

void setup(){
  n = in();
  s = in();
  line.resize(n);
  foreach(i,line)i=in();
}

int main(){
  setup();
  vector<mint> dp(s+1,0);
  mint ans(0);
  rep(i,n){
    dp[0] += 1;
    vector<mint> ndp(s+1,0);
    rep(j,s+1){
      ndp[j]+=dp[j];
      if(line[i]+j<=s){
        ndp[j+line[i]]+=dp[j];
      }
    }
    dp = ndp;
    ans += dp[s];

  }
  cout << ans << endl;
  return 0;
}
