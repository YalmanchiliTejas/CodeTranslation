#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    ll k;
    cin >> k;
    string s = "FESTIVAL";
    vector<int> a(5000,0),c(5000,0);
    vector<ll> dp(8,0),b(5000,0);
    dp[0] = 1;
    int cnt = 0,n = 300;
    for (int i = 0;i < 7;++i) {
        for (int j = 1;j < 8;++j) a[cnt] = j,cnt++;
        for (int j = 0;j < n;++j) a[cnt] = i+1,cnt++;
    }
    for (int i = 0;i < cnt;++i) {
        dp[a[i]] += dp[a[i]-1];
        if (a[i] == 7) b[i] = dp[7];
    }
    for (int i = 4999;i > 0;--i) if (b[i]) while (k >= b[i]) k -= b[i],c[i]++;
    string ans = "";
    for (int i = 0;i < cnt;++i) {
        ans += s[a[i]-1];
        for (int j = 0;j < c[i];++j) ans += 'L';
    }
    cout << ans << endl;
}