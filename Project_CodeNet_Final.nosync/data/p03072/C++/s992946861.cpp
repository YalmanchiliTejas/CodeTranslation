#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    rep(i, N) cin >> H.at(i);

    int count = 0;
    rep(i, N) {  // 対象の山
        bool isTallest = true;
        for (int j = 0; j < i; j++) {  // 対象の山の一つ前の山
            if (H.at(i) < H.at(j)) {
                isTallest = false;
            }
        }
        if (isTallest == true) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
