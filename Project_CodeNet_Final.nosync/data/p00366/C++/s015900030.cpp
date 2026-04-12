#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int n;
    cin >> n;
    int t[100000];
    int maxi = -1;
    rep(i, n) {
        cin >> t[i];
        maxi = max(maxi, t[i]);
    }

    vector<int> div;
    for (int i = 1; i*i <= maxi; i++) {
        if (maxi%i == 0) {
            div.push_back(i);
            if (i != maxi/i) div.push_back(maxi/i);
        }
    }
    sort(div.begin(), div.end());

    //rep(i, div.size()) cout << div[i] << " ";

    int ans = 0;
    rep(i, n) rep(j, div.size()-1) {
        if (div[j] < t[i] && t[i] <= div[j+1]) ans += div[j+1]-t[i];
    }
    
    cout << ans << endl;

    return 0;
}
