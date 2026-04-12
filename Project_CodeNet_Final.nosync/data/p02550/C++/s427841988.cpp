#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)


int main() {
    ULL N, X, M; cin >> N >> X >> M;

    int s = 0;
    ULL ans = 0;
    int I[100000]; rep(i, M) I[i] = -1;
    {
        int i = 1;
        while (N != 0) {
            ans += X; I[X] = i; N--;
            X = X * X % M; i++;
            if (I[X] != -1) { s = i - I[X]; break; }
        }
    }

    if (N != 0) {
        vector<ULL> V(s + 1);
        rep(i, s) { V[i + 1] = V[i] + X; X = X * X % M; }
        ans += (N / s) * V[s]; N %= s;

        ans += V[N];
    }

    cout << ans << endl;

    return 0;
}