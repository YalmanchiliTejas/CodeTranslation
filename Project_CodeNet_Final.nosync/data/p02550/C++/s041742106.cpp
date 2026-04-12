#include <bits/stdc++.h>

//#define DBG

#ifdef DBG
#include <unistd.h>
#endif
using namespace std;

using ll = long long;

const ll MOD = 998244353;

ll tbl[100000 + 1] = {0LL};
ll tblsum[100000 + 1] = {0LL};

ll N, X, M;

ll myf(ll x, ll m) {
    return (x * x) % m;
}

ll solver(){
    ll ans = 0;
    ll a = X;
    for(int i = 1; i <= N; i++){
        ans += a;
        a = myf(a, M);
        if(a == 0){
            return ans;
        }
    }
    return ans;
}

ll solver2(){
#ifdef DBG
    cout << "Ran sol2" << endl;
#endif
    // ループを見つける
    ll block = 0;
    ll a = X;

    ll loop = 0;
    ll bblock;
    for(ll i = 1; i <= N; i++){
        if(tbl[a] != 0) {
            #ifdef DBG
            cout << "Already " << a << " on " << tbl[a] << " i = " << i << endl;
            //sleep(3);
            #endif
            bblock = block - tblsum[a];
            loop = i - tbl[a];
            break;
        }
        tbl[a] = i;
        tblsum[a] = block;
        block += a;
        a = myf(a, M); // ここからaはa_{i+1}
        if(a == 0){
            return block;
        }
    }
    ll ans = tblsum[a] + bblock * ((N - (tbl[a] - 1)) / loop);

    ll ex = (N - (tbl[a] - 1)) % loop;

    for(int i = 1; i <= ex; i++){
        ans += a;
        a = myf(a, M);
        if(a == 0){
            return ans;
        }
    }

    return ans;
}

int main(){
    cin >> N >> X >> M;
    cin.ignore();

    ll ans;
    if(N <= M){
        ans = solver();
    } else {
        ans = solver2();
    }
    cout << ans << endl;

    return 0;
}

    