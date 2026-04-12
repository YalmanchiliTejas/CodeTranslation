#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
#ifdef LOCAL
#define debug(x) cerr << #x << ": " << x << endl
#else
#define debug(x)
#endif
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

string N; //　10 進法で高々 100 桁
int K;

ll dp[100][4][2];
ll solve(int n, int nokori, int pitari){
	if(nokori < 0) return 0LL;
	if(n == N.size()){
		if(nokori == 0) return 1LL;
		else return 0LL;
	}
	if(dp[n][nokori][pitari] != -1) return dp[n][nokori][pitari];
	ll ret = 0LL;
	if(pitari == 1 && N[n]-'0' == 0) ret += solve(n+1, nokori, 1);
	else ret += solve(n+1, nokori, 0);
	for(int i=1; i<10; i++){
		if(pitari == 1 && N[n]-'0' < i) continue;
		if(pitari == 1 && N[n]-'0' == i) ret += solve(n+1, nokori-1, 1);
		else ret += solve(n+1, nokori-1, 0);
	}
	return dp[n][nokori][pitari] = ret;
}

// 0 でない数字が K 個
signed main(){
	cin >> N >> K;
	memset(dp, -1, sizeof(dp));
	cout << solve(0, K, 1) << endl;
}