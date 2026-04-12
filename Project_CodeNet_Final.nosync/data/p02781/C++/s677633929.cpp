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
    reverse(ALL(S));

    vector<vector<ll>> f(L+1, vector<ll>(K+1)), g(L+1, vector<ll>(K+1));
    rep(i, L) f[i][0] = g[i][0] = 1;

    rep2(i, 1, L+1) rep2(j, 1, K+1){
        int x = S[i-1] - '0';
        if(x > 0){
            f[i][j] += f[i-1][j-1];
            f[i][j] += (x-1) * g[i-1][j-1];
            f[i][j] += g[i-1][j];
        }
        else{
            f[i][j] += f[i-1][j];
        }
        g[i][j] += 9 * g[i-1][j-1];
        g[i][j] += g[i-1][j];
    }
    cout << f[L][K] << endl;
}