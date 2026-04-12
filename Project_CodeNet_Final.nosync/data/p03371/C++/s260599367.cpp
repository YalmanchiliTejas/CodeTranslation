#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

long long a, b, c;
int x, y;
int main() {
    cin >> a >> b >> c >> x >> y;
    long long mincost = 1e12;
    int maxAB = max(x, y);
    for(int i = 0; i <= maxAB; ++i) {
        long long cost = c*i*2;
        int acnt = max(x-i, 0);
        int bcnt = max(y-i, 0);
        cost += (a*acnt + b*bcnt);
        chmin(mincost, cost);
    }
    cout << mincost << endl;
}