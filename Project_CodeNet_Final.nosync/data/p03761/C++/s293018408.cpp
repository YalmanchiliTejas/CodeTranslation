#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s[n];
    for ( int i = 0 ; i < n ; i++ ) cin >> s[i];
    for ( int i = 0 ; i < 26 ; i++ ) {
        char a = i + 'a';
        int x = 0 , y = 0;
        for ( int j = 0 ; j < n ; j++ ) {
            x = 0;
            for ( int k = 0 ; k < s[j].length() ; k++ ) {
                if ( s[j][k] == a ) x++;
            }
            if( j == 0 ) y = x;
            y = min( x , y );
        }
        for ( int j = 0 ; j < y ; j++ ) cout << a;
    }
}