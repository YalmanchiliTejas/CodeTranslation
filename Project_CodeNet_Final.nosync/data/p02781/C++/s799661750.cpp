//しゃきょ〜〜〜〜〜〜〜〜〜〜〜〜〜	

#include <bits/stdc++.h>

using namespace std;
using ll =long long;
//nCm 
const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++){
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k){
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//nCmここまで

#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
const ll INF = 1LL << 60;

//Write From this Line

const int mod = 1e9+7;
int dp[105][4][2];//0埋めされている
int main()
{
	string s ;
	cin >> s ;
	int n = s.size();//桁数がn
	int K ;
	cin >> K ;
	dp[0][0][0] = 1 ;
	//配る
	rep(i,n) rep(j,4) rep(k,2) {//iが小さい順にやるのが大事
		int nd = s[i] -'0' ; //nの今の桁
		rep(d,10){
			//次の桁を0~9野どれにするか
			int ni = i+1 , nj = j , nk = k; //遷移先
			if(d != 0) nj ++ ;
			if(nj > K) continue; //遷移先は無い
			if(k==0) {
				if(d > nd) continue;//超えちゃう
				if(d < nd) nk = 1 ;//以下になることが確定
			}
			dp[ni][nj][nk] += dp[i][j][k]; 
		}
	}
	int ans = dp[n][K][0] + dp[n][K][1];
	cout <<ans << endl;
}
