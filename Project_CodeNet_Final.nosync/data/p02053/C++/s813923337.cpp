#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int h,w;
    string s[1010];
    cin >> h >> w;
    for (int i = 0;i < h;++i) cin >> s[i];
    int mn = 1000000,mx = 0,ans;
    for (int i = 0;i < h;++i) {
        for (int j = 0;j < w;++j) if (s[i][j] == 'B') {
            mn = min(mn,i+j);
            mx = max(mx,i+j);
        }
    }
    ans = mx-mn;
    mn = 1000000,mx = 0,ans;
    for (int i = 0;i < h;++i) {
        for (int j = w-1;j >= 0;--j) if (s[i][j] == 'B') {
            mn = min(mn,i+w-1-j);
            mx = max(mx,i+w-1-j);
        }
    }
    ans = max(ans,mx-mn);
    cout << ans << endl;
    return 0;
}
