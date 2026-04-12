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
const int N = 200005;

ll dp[N], sum[N], v[N];

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	sum[1] = v[1];
	for(int i = 3; i <= n; i+=2)
		sum[i] = v[i] + sum[i-2];
	for(int i = 2; i <= n; i++){
		if(i&1){
			dp[i] = max(dp[i-2] + v[i], dp[i-1]);
		} else {
			dp[i] = max(dp[i-2] + v[i], sum[i-1]);
		}
	}
	cout << dp[n] << endl;
}

int main(){
	fastio;
	int t = 1;
	//cin >> t;
	while(t--)
		solve();
	return 0;
}
