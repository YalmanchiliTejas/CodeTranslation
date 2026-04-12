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
    int N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> B(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
        B[i] = A[i];
    }
    sort( A.begin(), A.end() );
    long long a = A[N/2-1];
    long long b = A[N/2];

    for ( int i = 0; i < N; i++ ) {
        if ( a >= B[i] ) { cout << b << endl; }
        else { cout << a << endl; }
    }


    return 0;
}