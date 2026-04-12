#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;++i) cin >> a[i];
    vector<int> dp(n+2,INT_MAX);
    dp[0] = INT_MIN;
    for (int i = 0;i < n;++i) {
        int j = upper_bound(dp.begin(),dp.end(),-a[i])-dp.begin();
        dp[j] = -a[i];
    }
    // p_ary(dp,0,n+2,i);
    for (int i = 1;i < n+2;++i) if (dp[i] == INT_MAX) {
        cout << i-1 << endl;
        return 0;
    }
}