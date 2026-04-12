#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
ll const mod = 1e9+7;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    string s;
    int d;
    cin >> s >> d;
    int n = s.size();
    vector<vector<int>> dp1(n+1,vector<int>(d,0)),dp2(n+1,vector<int>(d,0));
    dp1[0][0] = 1;
    for (int i = 0;i < n;++i) {
        int t = s[i]-'0';
        for (int j = 0;j < d;++j) {
            for (int k = 0;k < 10;++k) {
                (dp2[i+1][(j+k)%d] += dp2[i][j]) %= mod;
                if (k == t) dp1[i+1][(j+k)%d] += dp1[i][j];
                else if (k < t) (dp2[i+1][(j+k)%d] += dp1[i][j]) %= mod;
            }
        }
    }
    cout << (dp1[n][0]+dp2[n][0]-1+mod)%mod << endl;
    return 0;
}