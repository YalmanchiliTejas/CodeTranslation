#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<b;++i)
#define ALL(a) a.begin(),a.end()
#define INIT(a,b) memset(a,b,sizeof(a))
using lint = long long int;

int main() {
    lint N, X, M;
    cin >> N >> X >> M;

    vector<int> t(M, -1);
    vector<lint> S = {X};
    t[X] = 0;

    lint A = X;    
    for_(i,0,M) {
        A = (A * A) % M;
        if (t[A] == -1) {
            S.push_back(A);
            t[A] = i + 1;
        }
        else {
            break;
        }
    }

    int piv = t[A];
    lint ans = 0;
    int rep = (int)min(N, (lint)piv);
    for_(i,0,rep) ans += S[i];

    // cerr << ans << " " << A << " " << piv << " " << S.size() << endl;

    if (N - piv > 0) {
        N -= piv;
        int m = S.size() - piv;
        lint tmp = N / m;
        // cerr << N << " " << m << " " << tmp << endl;
        for_(i,piv,(int)S.size()) ans += S[i] * tmp;
        tmp = N % m;
        for_(i,piv,piv+(int)tmp) ans += S[i];
    }

    cout << ans << endl;
}