#include<bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
#define rep(i, n) for(int i=0;i<(n);++i)
#define INF (1ll<<60)
#define FI first
#define SE second
typedef pair<int, int> pii;
#define l_b lower_bound
#define u_b upper_bound

string S;

signed main() {
    cin >> S;
    rep(i, S.size() - 1) {
        if (S[i] == 'A') {
            if (S[i + 1] == 'C') {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}