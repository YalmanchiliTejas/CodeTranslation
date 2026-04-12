#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int N = 100 + 5;

ll eq[N][N], dp[N][N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string s;
	int K;
	cin >> s >> K;
	eq[0][0] = 1;
	rep(i,1,s.length()+1){
		int cur = s[i-1] - '0';
		rep(j,0,s.length()){
			eq[i][j + (cur != 0)] += eq[i-1][j];
		}
		rep(j,0,cur){
			rep(k,0,s.length()){
				dp[i][k + (j != 0)] += eq[i-1][k];
			}
		}
		rep(j,0,10){
			rep(k,0,s.length()){
				dp[i][k + (j != 0)] += dp[i-1][k];
			}
		}
	}
	cout << eq[s.length()][K] + dp[s.length()][K] << '\n';
}
