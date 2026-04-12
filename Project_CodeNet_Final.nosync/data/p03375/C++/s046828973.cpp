#include <bits/stdc++.h>
#define int long long
using namespace std;
int pw(int a, int b, int c){
	if (b==0) return 1;
	if (b==1) return a;
	if (b%2){
		int rs = pw(a, b-1, c);
		return (rs*a)%c;
	}
	int rs = pw(a, b/2, c);
	return (rs*rs)%c;
}
vector<int> fact;
int gc(int a, int b, int c){
	int X = fact[a];
	int Y = (fact[b] * fact[a-b]) % c;
	return (X * pw(Y, c-2, c)) % c;
}
int dp[3005][3005];
signed main(){
	//freopen("1.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
	int w = pw(2, n, m-1);
	int res = pw(2, w, m);
    int v = 0;
    fact.push_back(1);
    for (int i=1; i < 5000; i++){
		fact.push_back(fact.back() * i);
		fact.back() %= m;
    }
    for (int i=0; i < 3005; i++) for (int j=0; j < 3005; j++) dp[i][j] = 0;
    dp[0][0] = 1;
	for (int i=1; i < 3005; i++){
		for (int j=3004; j >= 0; j--){
			dp[i][j] = 0;
			if (j+1 <= 3004){
				dp[i][j+1] += dp[i-1][j];
				dp[i][j+1] %= m;
			}
			dp[i][j] = dp[i-1][j] * (j+1);
			dp[i][j] %= m;
		}
	}
    for (int bits = 1; bits <= n; bits++){
        int rest = n - bits;
        int dop = pw(2, rest, m-1);
        int var = pw(2, dop, m);
		int th = 0;
       // cout << dp[2] << endl;
        for (int j=1; j <= bits; j++){
			int C = pw(2, rest, m);
			C = pw(C, j, m);
            C *= dp[bits][j];
            C %= m;
			th += C;
			th %= m;
        }
        th++;
        th *= var;
        th %= m;
        th *= gc(n, bits, m);
        //cout << th << endl;
        if (bits % 2) v += th;
        else v -= th;
        v %= m;
    }
    res -= v;
    res %= m;
    if (res < 0) res += m;
    cout << res;
}
