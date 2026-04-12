#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//dp[i][j][k] : i行目まで決めて，j個の非0を使って，ｋ→0:そこまでの桁はｓと一致，→1：そこまでの桁で既にｓ以下であることが確定．
int dp[105][4][2];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	int K;
	cin >> K;
	//初期値
	dp[0][0][0] = 1;
	rep(i, n)rep(j, 4)rep(k, 2){
		//今見ている桁の数
		int nd = s[i]-'0';
		//この桁に入れる値
		rep(d, 10){
			//ni:次の桁，nj:何個の非0を使ったか，nk:s以下であることが既に確定されているか
			int ni = i+1, nj = j, nk = k;
			//dが0でなければ「非0の値を使う」という意味なのでnjの値をインクリメント
			if(d != 0) nj++;
			//njの値がKを超えることはない
			if(nj > K) continue;
			//sとの大小を比べる必要あり
			if(k == 0){
				//この桁に入れる予定の値がsとの大小関係を満たさない場合
				if(d > nd) continue;
				//s未満であることが確定する場合
				if(d < nd) nk = 1;
			}
			dp[ni][nj][nk] += dp[i][j][k];
		}
	}
	int ans = dp[n][K][0] + dp[n][K][1];
	cout << ans << endl;
	return 0;
}