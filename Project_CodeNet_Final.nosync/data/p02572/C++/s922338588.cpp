#include <bits/stdc++.h>

//#define DBG

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

ll N;
vector<ll> A;


int main(){

    cin >> N;
    cin.ignore();
    ll sum = 0;
    for(int i = 0; i < N; i++){
        ll tmp;
        cin >> tmp;
        A.push_back(tmp);
         sum += tmp;
    }
    cin.ignore();

    ll ans = 0;
    for(int i = 0; i < N - 1; i++){
        sum -= A[i];
        ll msum = sum % MOD;
        ans += ((A[i] % MOD) * msum) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;

    #ifdef DBG
    ll naive_ans = 0;
    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            naive_ans += ((A[i] % MOD) * (A[j] % MOD)) % MOD;
            naive_ans %= MOD;
        }
    }
    if(ans == naive_ans) cout << "SUC" << endl;
    else {
        cout << "ERR naive = " << naive_ans << endl;
    }

    cout << 200000LL * 1000000000LL << endl;
    #endif
    return 0;

}