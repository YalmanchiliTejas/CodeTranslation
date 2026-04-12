#include<iostream>
using namespace std;
typedef long long ll;
const int N = 51;
ll bu[N], p[N];
ll recursive(int n, ll x) {
    if (n == 0) { //level 0 burger
        return 1; //is p
    }
    if (x == 1) { //bottom (not level 0 burger)
        return 0; //is b
    } else if (x <= bu[n] / 2) { //切り捨てで真ん中の1個左まで
        return recursive(n - 1, x - 1);
    } else if (x == bu[n] / 2 + 1) {
        return 1 + recursive(n - 1, x - 2);
    }
    return p[n - 1] + 1 + recursive(n - 1, x - bu[n - 1] - 2);
}
int main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll x;
    cin >> n >> x;
    p[0] = 1;
    bu[0] = 1;
    for (int i = 1; i < N; ++i) {
        bu[i] = 2 * bu[i - 1] + 3;
        p[i] = 2 * p[i - 1] + 1;
    }
    cout << recursive(n, x) << endl;
    return 0;
}
