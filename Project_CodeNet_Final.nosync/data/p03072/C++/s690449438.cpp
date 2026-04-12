#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n;
    cin >> n;

    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    int ans = 1;
    int max_h = h[0];
    for(int i = 1; i < n; i++){
        if((h[i] >= h[i-1]) && (max_h <= h[i])) ans++;
        max_h = max(max_h, h[i]);
    }
    cout << ans << endl;
    return 0;
}