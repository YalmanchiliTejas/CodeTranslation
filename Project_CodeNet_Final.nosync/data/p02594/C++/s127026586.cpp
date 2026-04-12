#include <cstdio>
#include <functional>
#include <algorithm>
#include <vector>
#include <limits>
#include <numeric>
#include <type_traits>
#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using Vec = vector<ll>;
using P = pair<ll, ll>;
using VecP = vector<P>;
#define rep(i, n, s) for (int i = s; i < (int)(n); i++)

//static const ll MOD = 1000000007;
//static const ll INF = 1000000000000000000;
//#define PI 3.14159265358979323846
//
//int gcd(int x, int y) { return (x % y) ? gcd(y, x % y) : y; }
//
//int findSumDigits(int s) {
//    int num = 0;
//    int temp = 0;
//    while (s) {
//        temp = s % 10;
//        num += temp;
//        s = s / 10;
//    }
//    return num;
//}
//
//int countDivisorNum(int n) {
//    int count = 0;
//    for (int i = 1; i <= n; i++) {
//        if (n % i == 0) {
//            count++;
//        }
//    }
//    return count;
//}

int main() {
    ll x;
    cin >> x;

    if(x>=30){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }




    return 0;
}