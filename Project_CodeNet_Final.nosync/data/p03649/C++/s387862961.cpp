#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 2000000010;
constexpr ll INF= 2000000000000000000;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

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

ll mod(ll val) {
    ll res = val % MOD;
    if(res < 0) {
        res += MOD;
    }
    return res;
}

// N^P mod M（ただしM == -1の時はmodを取らない）
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
    ll N;
    cin >> N;
    vector<ll> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    ll ret = 0;
    while(true) {
        ll cnt = 0;
        vector<ll> cnt2(N);
        for(int i = 0;i < N;i++) {
            cnt2.at(i) = vec.at(i) / N;
            vec.at(i) = vec.at(i) % N;
        }
        ll sum = 0;
        for(int i = 0;i < N;i++) {
            sum += cnt2.at(i);
        }
        ret += sum;
        for(int i = 0;i < N;i++) {
            vec.at(i) += sum - cnt2.at(i);
        }
        bool cnt3 = true;
        for(int i = 0;i < N;i++) {
            if(vec.at(i) >= N) {
                cnt3 = false;
            }
        }
        if(cnt3 == true) {
            break;
        }
    }
    cout << ret << endl;
}          