#include <iostream>
#include <numeric>
#include <bits/stdc++.h>
using namespace std;
// long long -> lint
using lint = long long;
// fast cin and cout from hitonanode-san's code
// w/o 71 ms -> w/ 18 ms (tested on ABC148-D with C++14(GCC 5.4.1))
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;


int main(){
    // input
    int N, M;
    cin >> N >> M;

    // out
    printf( N==M ? "Yes" : "No" );
} 