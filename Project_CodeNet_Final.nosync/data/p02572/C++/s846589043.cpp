#include<bits/stdc++.h>
#define int long long
#define p pair<int, int>
#define endl '\n'
const int INF = 1000000001;

using namespace std;

const int C = 1000000007;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), pref = {0};
    for (int q = 0; q < n; q++){
        cin >> a[q];
        pref.push_back((pref.back()+a[q]) % C);
    }
    int ans = 0;
    for (int q = 0; q < n; q++){
        ans += a[q]*pref[q] % C;
    }
    cout << ans % C << endl;
    return 0;
}
