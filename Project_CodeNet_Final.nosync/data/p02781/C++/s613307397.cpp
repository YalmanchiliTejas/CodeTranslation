#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    vector<array<ll,4>> dp0(n+1),dp1(n+1);
    for (int i = 0;i < n+1;++i) dp0[i].fill(0);
    for (int i = 0;i < n+1;++i) dp1[i].fill(0);
    dp0[0][0] = 1;
    for (int i = 0;i < n;++i) {
        for (int l = 0;l < k+1;++l) dp1[i+1][l] += dp1[i][l];
        for (int l = 0;l < k;++l) dp1[i+1][l+1] += dp1[i][l]*9;
        if (s[i] > '0') {
            for (int l = 0;l < k;++l) {
                dp0[i+1][l+1] += dp0[i][l];
                dp1[i+1][l+1] += dp0[i][l]*(s[i]-'0'-1);
            }
            for (int l = 0;l < k+1;++l) dp1[i+1][l] += dp0[i][l];
        } else for (int l = 0;l < k+1;++l) dp0[i+1][l] += dp0[i][l];
    }
    cout << dp0[n][k]+dp1[n][k] << endl;
}