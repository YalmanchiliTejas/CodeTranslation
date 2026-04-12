#include"bits/stdc++.h"
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep3(i,m,n) for(int (i)=m;(i)<=(n);(i)++)
#define rep3rev(i,m,n) for(int (i)=m;(i)>=(n);(i)--)
#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using P = pair<int, int>;

int dp[105][4][2];

void Main() {
    string s; int k; 
    cin >> s >> k;
    int n = s.size();
    
    // dp[i][j][full] 
    // 上から i 桁目まで決定, 0 <= i <= n
    // 非ゼロをいくつ使ったか ０ <= j <= k <= 3 
    // full = 0, if 上から i 桁目が s のそれと一致
    // full = 1, otherwise

    dp[0][0][0] = 1;
    dp[0][0][1] = 0;
    
    rep(i, n) rep(j, 4) rep(full, 2){
        int nd = s[i] - '0';
        rep(d, 10){
            int ni = i+1;
            int nj = j;
            int nfull = full;
            if(d != 0) nj++;
            if(nj > k) continue;
            if(full == 0){
                if(d > nd) continue;
                if(d < nd) nfull = 1;
            }  
            dp[ni][nj][nfull] += dp[i][j][full];
        }
    }
    
	cout << dp[n][k][0] + dp[n][k][1] << endl;
	return;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
	return 0;
}
