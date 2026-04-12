#include "bits/stdc++.h"
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using li = int64_t;
using P = pair<int, int>;

int main() {
    string S;
    cin >> S;

    int cnt = 0;
    rep(i, 3) cnt += (S[i] == 'A' ? 1 : -1);
    cout << (abs(cnt) == 3 ? "No" : "Yes") << endl;
}