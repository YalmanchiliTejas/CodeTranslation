#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0;i < n;++i) cin >> s[i];
    ll ans = 0;
    for (int i = 1;i < n/2;++i) {
        ll ret = 0;
        int l = 0,r = n-1;
        for (int j = 0;j < n;++j) {
            l += i;
            r -= i;
            if (r < i || l == r || (l > r && (l-r)%i == 0)) break;
            ret += s[l]+s[r];
            ans = max(ans,ret);
        }
    }
    cout << ans << endl;
    return 0;
}