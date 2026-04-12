#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll cnt[51];
ll len[51];
void init() {
    cnt[0] = 1LL;
    len[0] = 1LL;
    for (int i = 0; i < 50; i++) {
        cnt[i + 1] = (cnt[i] << 1) + 1LL;
        len[i + 1] = (len[i] << 1) + 3LL;
    }
}
bool falg = false;
void recur(ll N, ll &X, ll &total) {
    if (X == 0) {
        return;
    }
    if (X >= (len[N] - N)) {
        total += cnt[N];
        X -= len[N];
        if (X < 1) {
            return;
        }
        else if (X == 1) {
            total ++;
            return;
        }
        else {
            total ++;
            X--;
            recur(N, X, total);
        }
    }
    else {
        X--;
        recur(N - 1LL, X, total);
    }
}
int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);//bugs with `printf'
    cin.tie(NULL);//incompatible with `while (cin >> ...)'
    ll N, X, total;
    total = 0LL;
    cin >> N >> X;
    if (N == 0LL) {
        cout << 0 << endl;
        return 0;
    }
    if (X <= N) {
        cout << 0 << endl;
        return 0;
    }
    init();
    recur(N, X, total);
    cout << total << endl;
    return 0;
}