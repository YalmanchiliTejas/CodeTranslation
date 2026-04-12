#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
template <typename X, typename Y> istream& operator>>(istream& is, pair<X, Y>& p) { return is >> p.first >> p.second; }
#ifndef __COMBINATIONS_INCLUDED_
#define __COMBINATIONS_INCLUDED_
ll C(ll n, ll k) {
    if(k < 0) return 0;
    if(k == 0 or k == n) return 1;
    if(n >= 0) k = min(k, n - k);
    ll ans = 1, j = 2;
    for(ll i = 0; i < k; i++) {
        ans *= n - i;
        while(j <= k and ans % j == 0) {
            ans /= j;
            j++;
        }
    }
    return j == (k + 1) ? ans : 0;
}
#endif
ll pow(int x, int y) {
    int ans = 1;
    while(y--) {
        ans *= x;
    }
    return ans;
}
int nonzeros(int n) {
    return int(n % 10 != 0) + int(n / 10 % 10 != 0) + int(n / 100 % 10 != 0);
}
int get(string& N, ll K) {
    int ans = 0;
    for(int i = 0; i < K; i++) {
        ans *= 10;
        ans += N[i];
    }
    return ans;
}
ll solve(std::string N, long long K) {
    if(K == 0) {
        return 1;
    } else if(N.size() < K) {
        return 0;
    } else {
        ll ans = 0;
        for(int i = 0; i < pow(10, K); i++) {
            int nonzero_left = K - nonzeros(i);
            if(i < get(N, K)) {
                ans += C(N.size() - K, nonzero_left) * pow(9, nonzero_left);
            } else if(i == get(N, K)) {
                ans += solve(N.substr(K), nonzero_left);
            }
        }
        return ans;
    }
}
int main() {
    std::string N;
    std::cin >> N;
    for(char& c : N) {
        c -= '0';
    }
    long long K;
    scanf("%lld",&K);
    cout << solve(N, K) << endl;
    return 0;
}
