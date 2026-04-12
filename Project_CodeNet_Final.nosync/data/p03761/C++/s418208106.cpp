#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
	int n; cin >> n;
    vector<vector<int>> alpha(n, vector<int>(26));
    vector<string> S(n);
    for(int i = 0; i < n; i++) {
        cin >> S[i];
        for(int j = 0; j < S[i].size(); j++) {
            char k = S[i][j] - 'a';
            alpha[i][(int)k]++;
        }
    }
    string ans;
    string bet = "abcdefghijklmnopqrstuvwxyz";
    for(int j = 0; j < 26; j++) {
        int m = inf;
        for(int i = 0; i < n; i++) {
            m = min(m, alpha[i][j]);
        }
        for(int i = 0; i < m; i++) ans += bet[j];
    }
    cout << ans << endl;
	return 0;
}