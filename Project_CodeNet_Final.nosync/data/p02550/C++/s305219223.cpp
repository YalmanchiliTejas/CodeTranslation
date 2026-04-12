#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 2100000010;
constexpr ll INF= 2000000000000000000;
constexpr ll MOD = 998244353;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;
typedef pair<int,P> PP;

template<class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

void mod(ll &val, ll M) {
    val = val % M;
    if(val < 0) {
        val += M;
    }
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
    ll N;
    cin >> N;
    ll X,M;
    cin >> X >> M;
    vector<bool> used(M);
    vector<ll> cnt;
    ll cnt2 = X;
    while(true) {
        cnt.push_back(cnt2);
        if(used.at(cnt2)) {
            break;
        }
        used.at(cnt2) = true;
        cnt2 = (cnt2 * cnt2) % M;
    }
    ll itr = -1;
    for(int i = 0;i < cnt.size();i++) {
        if(cnt.at(i) == cnt.at(cnt.size() - 1)) {
            itr = i;
            break;
        }
    }
    ll Sum = 0;
    if(itr >= N) {
        for(int i = 0;i < N;i++) {
            Sum += cnt.at(i);
        }
    }
    else {
        ll K = cnt.size() - 1 - itr;
        for(int i = 0;i < itr;i++) {
            Sum += cnt.at(i);
        }
        ll cnt3 = 0;
        for(int i = itr;i < cnt.size() - 1;i++) {
            cnt3 += cnt.at(i);
        }
        Sum += (N - itr) / K * cnt3;
        for(int i = itr;i < itr + (N - itr) % K;i++) {
            Sum += cnt.at(i);
        }
    }
    cout << Sum << endl;
}