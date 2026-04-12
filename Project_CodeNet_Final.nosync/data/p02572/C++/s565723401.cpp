#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<b;++i)
#define ALL(a) a.begin(),a.end()
#define INIT(a,b) memset(a,b,sizeof(a))
using lint = long long int;

int main() {
    int N;
    cin >> N;

    vector<lint> A(N);
    for_(i,0,N) cin >> A[i];

    lint sum = A[0], ans = 0, MOD = (lint)1e9 + 7;
    for_(i,1,N) {
        lint add = (sum * A[i]) % MOD;
        ans = (ans + add) % MOD;
        sum = (sum + A[i]) % MOD;
    }
    cout << ans << endl;
}