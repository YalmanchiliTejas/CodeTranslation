#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(void){
    string s;
    int k;
    cin >> s >> k;
    
    vector<vector<ll>> dp0(s.size(), vector<ll>(k+1, 0));
    vector<vector<ll>> dp1(s.size(), vector<ll>(k+1, 0));
    dp0[0][1] = ctoi(s[0])-1;
    dp1[0][1] = 1;
    for (int i = 1; i < s.size(); i++) {
        int num = ctoi(s[i]);
        dp0[i][1] = 9;
        for (int j = 1; j <= k; j++) {
            dp0[i][j] += dp0[i-1][j-1]*9 + dp0[i-1][j];
            if (num == 0) {
                dp1[i][j] = dp1[i-1][j];
            }
            else {
                dp1[i][j] = dp1[i-1][j-1];
                dp0[i][j] += dp1[i-1][j-1] * (num-1);
                dp0[i][j] += dp1[i-1][j];
            }
        }
    }
    //for (int i = 0; i < s.size(); i++)
        //cout << dp0[i][1] << " " << dp0[i][2] << " " << dp1[i][1] << " " << dp1[i][2] << endl;
    cout << dp1[s.size()-1][k]+dp0[s.size()-1][k] << endl;
}