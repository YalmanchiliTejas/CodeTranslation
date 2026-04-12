#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)

ll num[111], N;

ll miman[111][5];
ll eq[111][5];

int main(){

    string s;
    cin >> s;
    N = s.size();
    rep(i, N)num[i + 1] = s[i] - '0';
    eq[0][0] = 1;
    rep(i, N){
        ll to = i + 1;
        rep(j, 4){
            miman[to][j] += miman[i][j];
            miman[to][j + 1] += miman[i][j] * 9;
            if(num[to] == 0)eq[to][j] += eq[i][j];
            else miman[to][j] += eq[i][j];
            rep1(k, 9){
                if(k == num[to])eq[to][j + 1] += eq[i][j];
                if(k < num[i + 1])miman[to][j + 1] += eq[i][j];
            }
        }
    }
    
    ll K;
    cin >> K;
    cout << miman[N][K] + eq[N][K] << endl;
    
    return 0;
}