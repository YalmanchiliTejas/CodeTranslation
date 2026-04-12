#include <bits/stdc++.h>
using namespace std;

#define mainspring cout<<"mainspring\n";
#define barrel cout<<"barrel\n";
#define escapement cout<<"escapement\n";

#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end() 
#define sz(v) (int)((v).size())
#define INF INT_MAX
#define NINF INT_MIN
#define fs first
#define sd second
#define tik(i,a,b) for(int i = a; i < b; i++)
#define tok(i,a,b) for(int i = a; i >= b; i--)
#define error(args...) {string _s = #args; replace(_s.begin(), _s.end(), ',',' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it,args);}
#define int ll

typedef long long ll;
typedef unsigned long long ull;

typedef pair < int, int > pi;
typedef pair < pi, int > ppi;

typedef vector < int > vi;
typedef vector < vector < int > > vvi;
typedef vector < pi > vpi;
typedef vector < vpi > vvpi;
typedef vector < ppi > vppi;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << "\n";
    err(++it, args...);
}

const int MAX_N = 3000+100, DIM = 2;;

int dp[MAX_N][MAX_N][DIM], a[MAX_N];
int n;

int32_t main() {

	cin >> n;

	tik(i,1,n+1)
		cin >> a[i];

	tik(i,1,n+1) {
		dp[i][i][0] = a[i];
		dp[i][i][1] = 0; 
	}

	tok(i,n,1) {
		tik(j,i+1,n+1) {
			if(a[i] + dp[i+1][j][1] > a[j] + dp[i][j-1][1]) {
				dp[i][j][0] = a[i] + dp[i+1][j][1];
				dp[i][j][1] = dp[i+1][j][0];
			}
			else {
				dp[i][j][0] = dp[i][j-1][1] + a[j];
				dp[i][j][1] = dp[i][j-	1][0];
			}
		}
	}

	cout << dp[1][n][0] - dp[1][n][1];
}