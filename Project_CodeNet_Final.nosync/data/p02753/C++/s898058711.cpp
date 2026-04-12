
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <array>
#include <cmath>

using namespace std;

using ll = long long int;

// GCDを計算します
template <typename NumType>
NumType calcGCD(NumType a, NumType b) {
    if (a < b) {
        NumType tmp = a;
        a = b;
        b = tmp;
    }

    NumType r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

// 約数を数えます
template <typename NumType>
NumType cntDivisor(const NumType & num) {
    NumType cnt = 0;
    for(NumType i = 1; i * i <= num; ++i) {
        if(num % i == 0) {
            cnt++;
            if(i * i != num) cnt++;
        }
    }

    return cnt;
}

// [beg, end)の範囲を，添え字indexでループするfor文に置換します
#define FOR_RANGE(index, beg, end)     for (ll index = beg; index < N; ++index)

#define DEBUG(x)     std::cout << #x << " : " << x << "\n"

ll powMod(ll a, ll n, ll mod){
    if(n == 0) return 1;
    if(n%2 == 0)
        return powMod(a, n/2, mod) * powMod(a, n/2, mod) % mod;
    else
        return a * powMod(a, n-1, mod)% mod;
}

ll ncrMod(ll n, ll r, ll mod){
    ll x=1, y=1;
    for(ll i = 1; i <= r; ++i){
        x *= n-i+1;
        x %= mod;
        y *= i;
        y %= mod;
    }
    return x * powMod(y, mod-2, mod) % mod;
}

int main() {
    string S;

    cin >> S;

    int a_cnt = 0, b_cnt = 0;

    for (const auto c : S) {
        if (c == 'A') a_cnt++;
        if (c == 'B') b_cnt++;
    }

    if (a_cnt == S.length() || b_cnt == S.length()) cout << "No";
    else cout << "Yes";


    return 0;
}

