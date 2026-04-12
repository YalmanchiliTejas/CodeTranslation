#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i=0; i<(int)n; i++)
#define rep2(i, m, n) for(int i=(int)m; i<(int)n; i++)
#define ALL(a) a.begin(), a.end()
typedef long long ll;
typedef long double ld;

int main(){
    string S; int K;
    cin >> S >> K;
    int L = S.size();

    vector<vector<ll>> f(L+1, vector<ll>(K+1)), g(L+1, vector<ll>(K+1));
    g[0][0] = 1;
    rep(i, L) f[i+1][0] = 1;

    rep(i, L) rep(j, K){
        int x = S[i] - '0';
        f[i+1][j+1] += 9 * f[i][j] + f[i][j+1];
        if(x > 0) f[i+1][j+1] += (x-1) * g[i][j] + g[i][j+1];

        if((x > 0 && g[i][j] == 1) || (x == 0 && g[i][j+1] == 1)) g[i+1][j+1] = 1;
    }
    cout << f[L][K] + g[L][K] << endl;
}