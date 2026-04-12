#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

LL Z[51], Y[51];

LL part(int N, LL X) {
    if (N == 0) { if (X == 0) return 0; else return 1; }
    LL ans = 0;
    if (X <= 1) return ans;
    X--;
    if (X <= Z[N - 1]) return part(N - 1, X);
    ans += Y[N - 1]; X -= Z[N - 1];
    if (X <= 1) return ans + 1;
    ans++; X--;
    if (X <= Z[N - 1]) return ans + part(N - 1, X);
    ans += Y[N - 1]; X -= Z[N - 1];
    return ans;
}

int main() {
    int N; LL X; cin >> N >> X;
    Z[0] = Y[0] = 1;
    rep(i, N) Z[i + 1] = Z[i] * 2 + 3;
    rep(i, N) Y[i + 1] = Y[i] * 2 + 1;
    cout << part(N, X) << endl;
    return 0;
}