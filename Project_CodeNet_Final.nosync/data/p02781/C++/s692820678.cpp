#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const int MOD = 1e9 + 7;

int main(){
    string IN;
    int K;
    cin >> IN >> K;

    vector<int> N;
    for (char &c : IN) N.push_back(c - '0');

    int n = N.size();
    
    ll ans = 0;
    bool ok = false;
    if (K == 1) {
        rep(i, n) {
            if (i == 0) ans += N[0];
            else ans += 9;
        }
    } else if (K == 2) {
        rep(i, n)rep(j, n){
            if (j <= i) continue;
            if (i == 0) {
                if (!ok) {
                    ans += (N[0] - 1) * 9;
                    ans += N[j];
                    if (N[j] != 0) ok = true;
                } else {
                    ans += N[0] * 9;
                }
            } else {
                ans += 9 * 9;
            }
        }
    } else {
        rep(i, n)rep(j, n) {
            if (j <= i) continue;
            if (i == 0) {
                if (!ok) {
                    bool okk = false;
                    for (int k = j + 1; k < n; ++k) {
                        if (!okk) {
                            ans += (N[0] - 1) * 9 * 9;
                            if (N[j] > 0) {
                                ans += (N[j] - 1) * 9;
                                ans += N[k];
                            }
                            if (N[k] != 0) okk = true;
                        } else {
                            ans += (N[0] - 1) * 9 * 9;
                            ans += N[j] * 9;
                        }
                    }
                    if (N[j] != 0) ok = true;
                } else {
                    for (int k = j + 1; k < n; ++k) ans += N[0] * 9 * 9;
                }
            } else {
                for (int k = j + 1; k < n; ++k) ans += 9 * 9 * 9;
            }
        }
    }

    cout << ans << endl;
}