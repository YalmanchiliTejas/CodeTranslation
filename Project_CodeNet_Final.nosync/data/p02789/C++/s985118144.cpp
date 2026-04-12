#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>       // for next_permutation
#include <vector>
#include <cstdlib>
#define INF 998244353

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;

const ll MOD = 1e9+7;

static long gcd(long a, long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
/*
long long int facctorialMethod(int k){//階乗
    int sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}*/

long long int tousasum(long long int n){//等差数列
    return n*(n+1)/2;
}

unsigned GetDigit(unsigned num){//桁数
    unsigned digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}

bool is_prime(const unsigned n){
    switch(n){
        case 0: // fall-through
        case 1: return false;
        case 2: // fall-through
        case 3: return true;
    } // n > 3 が保証された

    if(n%2 == 0) return false;
    if(n%3 == 0) return false;
    // 2と3の倍数でないので6の倍数ではないことが保証された

    if(n%6 != 1 && n%6 != 5) return false;
    // 6の倍数前後の数(素数かもしれない数)であることが保証された

    // 6の倍数前後の数を使って試し割りをする
    for(unsigned i=5;i*i<=n;i+=6){
        if(n%i     == 0) return false; // 6n-1
        if(n%(i+2) == 0) return false; // 6n+1
    }

    return true;
}

map< ll, ll > prime_factor(ll n) {//素因数分解
    map< ll, ll > ret;
    for(ll i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1) ret[n] = 1;
    return ret;
}

ll calcNumOfCombination(ll n, ll r){
    ll num = 1;
    for(ll i = 1; i <= r; i++){
        num = num * (n - i + 1) / i;
    }
    return num;
}

int bubblesort(vector<int> array,int size){//バブルソート　転倒数
    int kaisu = 0;
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(array[i] > array[j]){
                int number = array[i];
                array[i] = array[j];
                array[j] = number;
                kaisu++;
            }
        }
    }
    return kaisu;
}

ll facctorialMethod(ll k){
    ll sum = 1;
    for (ll i = 1; i <= k; ++i)
    {
        sum = (sum * i)%MOD;
    }
    return sum;
}

// nPnの順列に対して処理を実行する
void foreach_permutation(int n, std::function<void(int *)> f) {
    int indexes[n];
    for (int i = 0; i < n; i++) indexes[i] = i;
    do {
        f(indexes);
    } while (std::next_permutation(indexes, indexes + n));
}





int main() {
 int N,M;
 cin >> N >> M;
 if(N==M){
     cout << "Yes" << endl;
 }else{
     cout << "No" << endl;
 }
}











