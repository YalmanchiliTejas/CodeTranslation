#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 2000000010;
constexpr ll INF= 2000000000000000000;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;
typedef pair<int,P> PP;

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

ll mod(ll val, ll M) {
    ll res = val % M;
    if(res < 0) {
        res += M;
    }
    return res;
}

template<typename T>
T RS(T N, T P, T M){
    if(P == 0) {
        return 1;
    }
    if(P < 0) {
        return 0;
    }
    if(P % 2 == 0){
        ll t = RS(N, P/2, M);
        if(M == -1) return t * t;
        return t * t % M;
    }
    if(M == -1) {
        return N * RS(N,P - 1,M);
    }
    return N * RS(N, P-1, M) % M;
}

int main() {
    int N;
    cin >> N;
    vector<ll> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    vector<ll> Sum(N + 1);
    for(int i = 0;i < N;i++) {
        Sum.at(i + 1) = Sum.at(i) + vec.at(i);
    }
    ll ret = 0;
    for(int i = 0;i < N;i++) {
        ll cnt = Sum.at(N) - Sum.at(i + 1);
        cnt %= MOD;
        ret += vec.at(i) * cnt;
        ret %= MOD;
    }
    cout << ret << endl;
}