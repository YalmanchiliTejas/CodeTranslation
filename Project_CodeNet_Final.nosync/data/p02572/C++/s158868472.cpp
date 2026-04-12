#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const ll INF = 1e16;

const ll MOD = (1e9 + 7);

void solver(int N, vector<ll> &A, ll &ans){

    vector<ll> c_sum(N);
    c_sum.at(N-1) = A.at(N-1);
    for(int i = N-2; i != -1; --i){
        c_sum.at(i) += (A.at(i)%MOD) + c_sum.at(i+1)%MOD;
    }
    /*
    for(int i = 0; i != N; ++i){
        cerr << c_sum.at(i) << " "s;
    }
    cerr << endl;
    */

    ll ans_buf{};
    //int pos = 1;
    for(int i = 0; i != N-1; ++i){
        ans_buf += ((A.at(i)%MOD)*(c_sum.at(i+1)%MOD))%MOD;
        ans_buf %= MOD;
        //++pos;
    }
    ans = ans_buf;

    return;    
}

int main(){

    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i != N; ++i) cin >> A.at(i);

    ll ans;
    solver(N, A, ans);

    cout << ans << endl;

    return 0;
}
