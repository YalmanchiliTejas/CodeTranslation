#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& x : a){
        cin >> x;
    }
    vector<int> rui(n, a[0]);
    for(int i = 1; i < n; ++i)
        rui[i] = rui[i - 1] + a[i];
    int ans = 1e9;
    for(int i = 0; i < n; ++i){
        int c = i + 1;
        int bound = rui[i] / c;
        ans = min(bound, ans);
    }
    cout << ans << endl;
}


