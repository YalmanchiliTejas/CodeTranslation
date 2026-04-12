#include <bits/stdc++.h>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define FOR(i,a,b) for(int i=a; i<(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define CLR(a) memset((a), 0 ,sizeof(a))
#define PB push_back
#define MP make_pair
#define SP << " " <<
const int INF = 1001001001;
const ll LINF = 100100100100100100;
const double EPS = 1e-10;
const long double PI  = acos(-1.0L);
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<double,double> PDD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
#define chmax(a,b) a = (((a)<(b))?(b):(a))
#define chmin(a,b) a = (((a)>(b))?(b):(a))

__attribute__((constructor))
void initial(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(15);
}

ll dp[10005][2][10];

signed main(){
	string s; cin>>s;
	int k; cin>>k;
	int n=s.size();
	dp[0][0][0]=1;
	rep(i,n){
		rep(j,k+1){
			dp[i+1][1][j+1] += dp[i][1][j]*9;
			dp[i+1][1][j] += dp[i][1][j];

			int ni=s[i]-'0';

			if(ni>0){
				dp[i+1][1][j+1] += dp[i][0][j]*(ni-1);
				dp[i+1][1][j] += dp[i][0][j];
				dp[i+1][0][j+1] = dp[i][0][j];
			}else{
				dp[i+1][0][j] = dp[i][0][j];
			}
		}
	}
	cout<<dp[n][0][k]+dp[n][1][k]<<endl;

	return 0;
}
