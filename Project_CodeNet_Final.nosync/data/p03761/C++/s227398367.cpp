#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define bn(n) (n).begin(), (n).end()
#define FOR(n) for(int i = 0; i < (int)n; i++)


void solve() {
    int n;
    cin >> n;
    string ans;
    vector<string> v;
    for (int i = 0; i <n; i++) {
        string a;
        cin >> a;
        v.push_back(a);
    }
    for (char c = 'a'; c <= 'z'; c++) {
        int temp = 1e9;
        for (int i = 0; i < n; i++) {
            int cnt = count(v[i].begin(), v[i].end(), c);
            if (cnt < temp) {
                temp = cnt;
            }
        }
        for (int i = 0; i < temp; i++) {
            ans += c;
        }
    }
    cout << ans << "\n";
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, i = 1;
    //cin >> t;
    while(t--) {
        //cout << "Case #" << i << ": ";
        solve();
        //i++;
    }
    return 0;
}
