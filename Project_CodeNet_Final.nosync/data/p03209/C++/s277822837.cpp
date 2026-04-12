#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll f(int N, ll X) {
    ll levelNlen = 1;
    for (int t = 0; t < N; t++) {
        levelNlen = levelNlen *2 + 3;
    }
    ll _levelNlen = (levelNlen - 3) / 2;
    if(N==0) return 1;
    if (X <= 1) return 0;
    ll res = 0;
    if (X <= 1 + _levelNlen) return f(N - 1, X - 1);
    return (1LL<<N)-1 + 1 + (X == 1+_levelNlen+1 ? 0 : f(N-1,X-(1+_levelNlen+1)));
}

int main() {
    int N;
    ll X;
    cin>>N>>X;
    cout << f(N, X) << endl;
}
