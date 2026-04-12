#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define endl '\n'
#define snd second
#define fst first
#define fastio cin.tie(NULL),cout.sync_with_stdio(true)

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector <int> vi;
typedef pair <ll,int> ii;
typedef pair <ii,int> iii;

const int mod = 1e9 + 7;
const ll INF = (1LL<<50);
const int N = 100005;

ll dp[3005][3005];

int main(){
	fastio;
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	// dp[i][j] = max diff with indices from i to j
	for(int L = n-1; L >= 0; L--){
		for(int R = L; R < n; R++){
			if(L == R){
				dp[L][R] = v[L];
			} else {
				dp[L][R] = max(v[L] - dp[L+1][R], v[R] - dp[L][R-1]);
			}
		}
	}
	cout << dp[0][n-1] << '\n';
	return 0;
}
