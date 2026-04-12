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
    
    string S;
    cin >> S;
    bool ans = false;
    for ( int i = 0; i < S.length()-1; i++ ) {
        if ( S[i] == 'A' && S[i+1] == 'C' ) { ans = true; }
    }
    
    cout << (ans ? "Yes" : "No" ) << endl;
    
    
    return 0;
}