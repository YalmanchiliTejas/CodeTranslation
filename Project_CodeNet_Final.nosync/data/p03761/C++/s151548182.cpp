#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string S;
    vector<int> amin(26, 1e9);
    rep(i, n) {
        cin >> S;
        vector<int> a(26, 0);
        rep(j, S.size()) {
            a[S[j] - 'a']++;
        }
        rep(j, 26) {
            amin[j] = min(amin[j], a[j]);
        }
    }
    rep(i, 26) {
        rep(j, amin[i]) {
            cout << (char)(i + 'a');
        }
    }
    cout << "\n";
}