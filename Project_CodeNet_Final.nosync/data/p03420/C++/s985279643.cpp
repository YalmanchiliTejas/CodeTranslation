#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <cmath>
#include <limits.h>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <stdio.h>
using namespace std;

long long MOD = 1000000007;

int main() {
    long long N,K;
    cin >> N >> K;    
    long long ans = N*N;
    for ( int i = 1; i <= K && i <= N; i++ ) {
        ans -= N;
    }
    for ( int i = K+1; i <= N; i++ ) {
        if ( K ) { ans -= (N/i)*K + ( N%i >= K ? K-1 : N%i ); }
    }
    cout << ans << endl;
    return 0;
}