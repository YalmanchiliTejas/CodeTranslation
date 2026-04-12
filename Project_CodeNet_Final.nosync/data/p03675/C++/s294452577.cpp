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
using namespace std;

int main() {
    
    int N;
    cin >> N;
    
    vector<long long> A, B, C;
    
    for ( int i = 0; i < N; i++ ) {
        long long a;
        cin >> a;
        A.push_back(a);
    }
    
    for ( int i = 0; i < N; i++ ) {
         if ( i%2 != N%2 ) {             
             C.push_back( A[i] );
         }
         else {
             B.push_back(A[i]);
         }
    }
    
   reverse( C.begin(), C.end() );
    
    for ( auto& a : C ) {
        cout << a << " ";
    }    
    for ( auto& a : B ) {
        cout << a << " ";
    }
    
    cout << endl;
    
    return 0;
}