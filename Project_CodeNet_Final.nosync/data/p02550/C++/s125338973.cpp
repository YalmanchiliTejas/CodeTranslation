#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = /*1'000'000'007LL;*/ 998'244'353LL;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

ll N;
ll X, M;

ll ans = 0;
ll idx[100001] ={};
ll sum[100001] ={};

signed main(){
    cin >> N >> X >> M;

    ll i = 1;
    sum[X] = ans = 1+X;
    N--;
    while(N > 0){
        X = X*X%M;
        ans += X;
        if(sum[X] > 0){
            ll cycle = ans - sum[X];
            ll len = i - idx[X];
            ll tmp = (N-1) / len;
            ans += tmp * cycle;
            N -= tmp * len;
            N--;
            break;
        }
        idx[X] = i;
        i++;
        sum[X] = ans;
        N--;
    }
    assert(N <= 100001);
    while(N > 0){
        X = X*X%M;
        ans += X;
        N--;
    }
    cout << ans-1 << endl;
}