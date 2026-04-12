#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long Int;


int main() {
    Int N;
    cin >> N;
    vector<Int> a(N);
    rep(i,N) cin >> a[i];


    Int ans = 0;

    while(true) {
        bool flag = true;
        rep(i,N) {
            if (a[i] >= N) {
                Int b = a[i] / N;
                a[i] -= b * N;
                rep(j,N) {
                    if (i != j) a[j] += b;
                }
                ans += b;
                flag = false;
            }
        }
        if (flag) break;
    }

    cout << ans << endl;

}