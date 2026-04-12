#include <bits/stdc++.h>
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = ((int)(n)-1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset(x, y, sizeof(x))
 
using namespace std;
 
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> P;
 
const int INF = 1e9;
const int MOD = 1e9+7;
const double EPS = 1.0e-12;
const double PI = acos(-1.0);

int dp[110][5][2];

int main() {
	string n;
	int K;
	cin >> n >> K;
	dp[0][0][0] = 1;
	for(int i = 0; i < n.size(); i++){
		int x = n[i]-'0';
		for(int j = 0; j <= K; j++){
			for(int k = 0; k <= 1; k++){
				for(int l = 0; l <= 9; l++){
					if(k==0 && l>x) continue;
					dp[i+1][j+(l!=0)][k||(l<x)] += dp[i][j][k];
				}
			}
		}
	}
	cout << dp[n.size()][K][0]+dp[n.size()][K][1] << endl;
	return 0;
}