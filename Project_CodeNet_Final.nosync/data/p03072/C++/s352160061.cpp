#include <iostream>
#include <string>
#include <limits>

#define rep(i, n) for(int i=0; i<(n); i++)

using namespace std;
const int INF = numeric_limits<int>::infinity();

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    int N, highest = 0, cnt = 0;
    cin >> N;
    rep (i, N) {
        int H;
        cin >> H;
        if (highest <= H) {
            highest = H;
            cnt++;
        }
    }
    cout << cnt << '\n';
}