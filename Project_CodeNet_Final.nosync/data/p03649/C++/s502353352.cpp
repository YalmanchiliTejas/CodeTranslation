#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

ll N, A[50];
ll ans = 0;

signed main(){
    cin >> N;
    rep(i, N) cin >> A[i];

    while(true){
        rep(i, N){
            ll tmp = (A[i]-A[i]%N)/N;
            ans += tmp;
            A[i] -= N*tmp;
            rep(j, N){
                if(i == j) continue;
                A[j] += tmp;
            }
        }
        bool flg = true;
        rep(i, N) flg &= (A[i] < N);
        if(flg) break;
    }
    cout << ans << endl;
}