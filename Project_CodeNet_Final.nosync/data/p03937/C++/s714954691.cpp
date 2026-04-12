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
    
    int count = 0;
    int H,W;
    cin >> H;
    cin >> W;
    
    
    for ( int i = 0; i < H; i++ ) {
        string s;
        cin >> s;
        
        for ( int j = 0; j < s.length(); j++ ) {
            if ( s[j] == '#' ) { count++; }
        }
        
    }
    
    cout << (count == (H-1 + W-1 + 1) ? "Possible" : "Impossible" ) << endl;
    
    return 0;
}