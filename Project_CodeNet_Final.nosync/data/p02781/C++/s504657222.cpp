#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ll, ll> p;
 
#define MOD 1000000007

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    int K;

    cin >> S >> K;

    vector<vector<int> > dp1(K + 1, vector<int>(S.length()));
    vector<vector<int> > dp2(K + 1, vector<int>(S.length()));

    for(int i = 0; i < S.length(); i++) {
        dp1[0][i] = 1;
    }

    dp1[1][0] = (S[0] - '0') - 1;
    dp2[1][0] = 1;

    for(int i = 1; i < S.length(); i++) {
        for(int j = 1; j <= K; j++) {
            dp1[j][i] = dp1[j - 1][i - 1] * 9 + dp1[j][i - 1];
        }
        if(S[i] == '0') {
            for(int j = 1; j <= K; j++) {
                dp2[j][i] = dp2[j][i - 1];
            }
        } else {
            for(int j = 1; j <= K; j++) {
                dp2[j][i] = dp2[j - 1][i - 1];
                dp1[j][i] += dp2[j - 1][i - 1] * ((S[i] - '0') - 1) + dp2[j][i - 1];
            }
        }
    }

    cout << dp1[K][S.length() - 1] + dp2[K][S.length() - 1] << endl;
}