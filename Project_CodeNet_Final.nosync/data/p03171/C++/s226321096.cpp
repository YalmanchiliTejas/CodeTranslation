


#include <bits/stdc++.h>

#define ll long long
#define PB push_back
#define MP make_pair

#define REP(i, n) for(int i=0;i<(int)(n);++i)
#define FOR(i,l,h) for(int i=(int)(l);i<=(int)(h);++i)
#define FORD(i,h,l) for(int i=(int)(h);i>=(int)(l);--i)

//#define max(a,b) a>b?a:b
//#define min(a,b) a>b?b:a

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

#define dump(x)  cerr << #x << " = " << (x) << endl
#define ALL(t) (t).begin(),(t).end()

using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int sum() { return 0; }

template<typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }


const int nax = 3003;
ll dp[nax][nax][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n;cin>>n;
	std::vector<ll> a(n);
	ll sum =0;
	REP(i,n){
		cin>>a[i];
		sum+=a[i];
	}

	REP(i,n){
		dp[i][i][0] = a[i];
		dp[i][i][1] = 0;
	}
	for(ll ad = 1 ; ad<n;ad++){
		for(ll i =0;i<n-ad;i++)
		{
			ll j = i+ad;
			dp[i][j][0] = max(dp[i+1][j][1] + a[i] , dp[i][j-1][1] + a[j]);


			dp[i][j][1] = min(dp[i+1][j][0] , dp[i][j-1][0] );

		}
	}

	//REP(i,n){REP(j,n){cout<<dp[i][j][0]<<" ";}cout << "\n";}

	std::cout << (2*dp[0][n-1][0]) - sum << "\n";
		return 0;
}
