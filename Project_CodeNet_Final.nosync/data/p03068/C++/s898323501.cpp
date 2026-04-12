#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

int main() {
    int N;
    cin >> N;
    vector<char> S(N);
    rep(i, N) cin >> S[i];
    int K;
    cin >> K;
    --K;
    rep(i, N) {
        if (S[i] != S[K]) S[i] = '*';
    }
    rep(i, N) cout << S[i];
    cout << "\n";
    return 0;
}
