#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;

int main() {
    
    int n, m; cin >> n >> m;
    vector<vector<int>> v(100, vector<int>(100,0));

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a-1][b-1] = 1;
        v[b-1][a-1] = 1;
    }

    vector<int> s;
    for (int i=0; i<n; i++) {
        s.emplace_back(i);
    }

    int ans = 0;
    do {
        if (s[0]==0) {
            bool check = true;
            for (int i=0; i<n-1; i++) {
                if (v[s[i]][s[i+1]]==0) check = false;
            }
            if (check) ans += 1;
        }
    } while (next_permutation(s.begin(), s.end()));

    cout << ans << "\n";
    
    return 0;
}