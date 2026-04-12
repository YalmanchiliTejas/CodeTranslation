#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>

using namespace std;
//DP用
template<class T> inline bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

//a^n mod を計算する関数
long long modpow(long long a,long long n,long long mod) {
    long long res = 1;
    while(n > 0) {
        if(n % 2 == 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

//a^(-1) mod すなわちaの逆元を返す関数
long long modinv(long long a,long long mod) {
    return modpow(a,mod-2,mod);
}

//最大公約数をを返す関数
long long gcd (long long a,long long b) {
    if(a % b == 0) {
        return b;
    }else {
        return (gcd(b,a%b));
    }
}

const long long INF = 1LL << 60;
const long long P = 1000000007;

//nCkを求める関数
long long conbi (long long n,long long k) {
    long long res = 1;
    long long inv;
    for(long long i = n-k+1; i <= n; i++) {
        res *= i;
        res %= P;
    }
    for(long long i = 1; i <= k; i++) {
        inv = modinv(i,P);
        res *= inv;
        res %= P;
    }
    return res;
}

int main() {
    char c;
    cin >> c;
    if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
        cout << "vowel";
    }else {
        cout << "consonant";
    }
    return 0;
}
