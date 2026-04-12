#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef std::vector<vector<int> > vvi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<vi> vvi;
typedef vector<vector<double>> vvd;
typedef vector<double> vd;

#define debugone(x) cerr << #x << " " << x << "\n"; cerr.flush();
#define debugtwo(x) cerr << #x << "-------------" << "\n";for(auto &it: x) cerr << it << " ";cerr << "\n"; cerr.flush();
#define debugthree(x_, i_, j_) cerr << #x_ << "------------" << "\n";cerr << "from " << i_ << " to " << j_ << "\n";for(ll k_=i_; k_<=j_; k_++) cerr << x_[k_] << " ";cerr << "\n"; cerr.flush();
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

const ll MOD = 1e9 + 7;
const int INF = 2e9;
const int MAX_LOG = 21;
const int MAX_N = 12800;

#define forn(i, n) for(int i = 0; i < n; i++)
#define forsn(i, s, n) for(int i = s; i < n; i++)
#define all(x) x.begin(), x.end()

ll expmod(ll x, ll n, ll mod){
	if(n == 0) return 1;
	else if(n % 2 == 0){
		ll temp = expmod(x, n / 2, mod);
		return (temp * temp) % mod;
	}
	else{
		return (expmod(x, n - 1, mod) * x) % mod;
	}
}

ll modinv(ll x, ll mod){
	return expmod(x, mod - 2, mod);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	cout << ((m >= n) ? "Yes" : "No") << endl;
}		
