#include <bits/stdc++.h>
using namespace std;

int N;
long long X;
long long num[51], pat[51];

long long rec(int k, long long x) {
    if (x <= 0) return 0;
    if (k == 0) return (x == 1) ? 1 : 0;
    if (num[k] == x) return pat[k];

    long long ret = 0;
    if (x > 1) {
        ret += rec(k-1, min(x-1, num[k-1]));
    }
    if (num[k-1]+2 <= x) {
        ret += 1 + rec(k-1, min(x-num[k-1]-2, num[k-1]));
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    num[0] = 1;
    pat[0] = 1;
    for (int i=1; i<=50; ++i) {
        num[i] = num[i-1] * 2 + 3;
        pat[i] = pat[i-1] * 2 + 1;
    }

    cin >> N >> X;

    cout << rec(N, X) << endl;

    return 0;
}