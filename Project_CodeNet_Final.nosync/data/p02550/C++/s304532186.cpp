#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 998244353;

ll f(ll X, ll M){
    return X%M;
}

int main(){
    ll N, X, M; cin >> N >> X >> M;
    ll SUM = X;
    vector<ll> A; A.push_back(X);
    vector<ll> ID(M+1, -1); ID[X] = 0;

    for(int cnt = 1; cnt < N; cnt++){
        X = f(X*X, M);
        A.push_back(X);
        //cout << X << " " << cnt << endl;
        if(ID[X] != -1){
            ll loop = 0; //ループでの総和
            ll n = cnt - ID[X]; //ループにかかる数
            ll n2 = max(ID[X], 0LL); // ループに入るまでの最初の数
            for(int i = ID[X]; i < cnt; i++) loop += A[i];
            ll n3 = (N - (n2))/n; //ループできる数
            SUM += (n3-1) * loop;
            ll n4 = N - n2 - n3*n; // 残り
            for(int i = 0; i < n4; i++) SUM += A[ID[X]+i];
            //cout << n2 << " " << n << " " << n3 << " " << n4 << endl;
            break;

        }
        SUM += X;
        ID[X] = cnt;
    }
    cout << SUM << endl;



}
