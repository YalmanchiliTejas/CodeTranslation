#include <bits/stdc++.h>
using namespace std;
using llong = long long;

llong N, x;
vector<llong> a(51); //a[i] = レベルiバーガーの層数
vector<llong> p(51);

llong rec(llong L, llong X) { //レベルLバーガーの下からX層でパティが含まれる枚数
    if (L == 0) return (X <= 0) ? 0 : 1;
    if (X <= 1) return 0ll;
    if (X <= a[L-1]+1) return rec(L-1, X-1);
    else return p[L-1] + 1 + rec(L-1, X-2-a[L-1]);
}

int main() {
    cin >> N >> x;
    a[0] = 1; p[0] = 1;
    for (int i = 0; i < 50; i++) {
        a[i+1] = 2*a[i] + 3;
        p[i+1] = 2*p[i] + 1;
    }
    cout << rec(N,x) << endl;
    return 0;
}