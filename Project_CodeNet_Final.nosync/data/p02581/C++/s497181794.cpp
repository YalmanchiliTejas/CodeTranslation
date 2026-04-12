#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

template<typename T1,typename T2>ostream& operator<<(ostream& os,const pair<T1,T2>& a) {os << "(" << a.first << ", " << a.second << ")";return os;}

const char newl = '\n';

int main() {
    int n,cnt = 0;
    cin >> n;
    vector<int> a(3*n+2);
    for (int i = 0;i < 3*n;++i) cin >> a[i],a[i]--;
    a[3*n] = a[3*n+1] = n;
    vector<vector<int>> dp0(n+1,vector<int>(n+1,-1e9)),dp1(n+1,vector<int>(n+1,-1e9));
    vector<int> b(n+1,-1e9);
    dp0[a[0]][a[1]] = dp0[a[1]][a[0]] = dp1[a[0]][a[1]] = dp1[a[1]][a[0]] = 0;
    b[a[0]] = b[a[1]] = 0;
    for (int i = 2;i < 3*n;i += 3) {
        int mx = *max_element(b.begin(),b.end());
        if (a[i] == a[i+2]) swap(a[i+1],a[i+2]);
        if (a[i+1] == a[i+2]) swap(a[i],a[i+2]);
        if (a[i] == a[i+2]) {
            cnt++;
            continue;
        }
        if (a[i] == a[i+1]) {
            for (int j = 0;j < n;++j) dp1[j][a[i+2]] = max(dp1[j][a[i+2]],dp0[j][a[i]]+1);
            for (int j = 0;j < n;++j) dp1[a[i+2]][j] = dp1[j][a[i+2]];
        }
        dp1[a[i]][a[i+1]] = max(dp1[a[i]][a[i+1]],dp0[a[i+2]][a[i+2]]+1);
        dp1[a[i+1]][a[i]] = dp1[a[i]][a[i+1]];
        dp1[a[i+1]][a[i+2]] = max(dp1[a[i+1]][a[i+2]],dp0[a[i]][a[i]]+1);
        dp1[a[i+2]][a[i+1]] = dp1[a[i+1]][a[i+2]];
        dp1[a[i+2]][a[i]] = max(dp1[a[i+2]][a[i]],dp0[a[i+1]][a[i+1]]+1);
        dp1[a[i]][a[i+2]] = dp1[a[i+2]][a[i]];
        for (int j = 0;j < 3;++j) for (int k = 0;k < 3;++k) if (j-k) dp1[a[i+j]][a[i+k]] = max(dp1[a[i+j]][a[i+k]],mx);
        for (int j = 0;j < 3;++j) for (int k = 0;k < n;++k) {
            dp1[a[i+j]][k] = max(dp1[a[i+j]][k],b[k]);
            dp1[k][a[i+j]] = dp1[a[i+j]][k];
        }

        if (a[i] == a[i+1]) {
            for (int j = 0;j < n+1;++j) {
                dp0[j][a[i+2]] = dp0[a[i+2]][j] = dp1[j][a[i+2]];
                b[j] = max(b[j],dp0[j][a[i+2]]);
                b[a[i+2]] = max(b[a[i+2]],dp0[j][a[i+2]]);
            }
        }
        for (int j = 0;j < 3;++j) for (int k = 0;k < 3;++k) if (j-k) {
            dp0[a[i+j]][a[i+k]] = dp1[a[i+j]][a[i+k]];
            b[a[i+j]] = max(b[a[i+j]],dp0[a[i+j]][a[i+k]]);
            b[a[i+k]] = max(b[a[i+k]],dp0[a[i+j]][a[i+k]]);
        }
        for (int j = 0;j < 3;++j) for (int k = 0;k < n+1;++k) {
            dp0[a[i+j]][k] = dp0[k][a[i+j]] = dp1[a[i+j]][k];
            b[k] = max(b[k],dp0[k][a[i+j]]);
            b[a[i+j]] = max(b[a[i+j]],dp0[k][a[i+j]]);
        }
    }
    int ans = 0;
    for (int i = 0;i < n+1;++i) ans = max(ans,*max_element(dp0[i].begin(),dp0[i].end()));
    cout << ans+cnt << endl;
}