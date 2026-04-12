#include <bits/stdc++.h>
#define ll long long
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
using namespace std;
const int tINF = (int)INT_MAX;
const long long lINF = (long long)LLONG_MAX;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef DEBUG
			assert(freopen("inp", "r", stdin));
			assert(freopen("out", "w",stdout));
	#else
			#define cerr if(false)cerr
    #endif
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = (int)s.size();
    vector <vector <vector<ll>>> dp(n + 1,vector <vector <ll>> (5,vector <ll>(2)));
    dp[0][0][1] = 1;
    for(int i =0 ; i < n; ++i){
        for(int j = 0; j <= k; ++j){
            if(s[i] == '0'){
                dp[i + 1][j][1] += dp[i][j][1];
            }
            else{
                dp[i + 1][j + 1][1] += dp[i][j][1];
                dp[i + 1][j][0] += dp[i][j][1];
                dp[i + 1][j + 1][0] += dp[i][j][1] * (s[i]-'0'-1);
            }
            dp[i + 1][j][0] += dp[i][j][0];
            dp[i + 1][j + 1][0] += dp[i][j][0] * 9;
        }
    }
    ll sum = 0;
    cout << dp[n][k][0] + dp[n][k][1] << '\n';
   cerr << "Time execute: " << (double)clock() / (double)CLOCKS_PER_SEC 
    << " sec" << endl;
}