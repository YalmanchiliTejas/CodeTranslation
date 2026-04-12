#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <cmath>
#include <limits.h>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <stdio.h>
using namespace std;

long long MOD = 1000000007;


long long P[51];
long long S[51];


long long func( long long l, long long k ) {
    if ( l == 0 ) { return 1; }
    if ( k <= 1 ) { return 0; }

    long long s = S[l];
    long long p = P[l];
    
    if ( s == k ) { return p; }

    if ( (s+1)/2 == k ) { return P[l-1]+1; }
    else if ( (s+1)/2 > k ) { return func(l-1, k-1); }
    else if ( (s+1)/2 < k ) { return P[l-1]+1+func(l-1,k-(2+S[l-1]) ); }
}


int main() {
    
    long long N;
    long long X;
    cin >> N >> X;

    P[0] = S[0] = 1;
    for ( int i = 1; i <= 50; i++ ) {
        P[i] = P[i-1]*2+1;
        S[i] = S[i-1]*2+3;
    }
    
    cout << func( N, X ) << endl;

    return 0;
}