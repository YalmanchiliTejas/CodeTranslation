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
    string s , t = "SS";
    cin >> n >> s;
    s += s[0];
    for ( int j = 0 ; j < 4 ; j++ ) {
        if ( j == 0 ) t = "SS";
        else if ( j == 1 ) t = "SW";
        else if ( j == 2 ) t = "WS";
        else t = "WW";
        for ( int i = 2 ; i <= n + 1 ; i++ ) {
            if ( t[i - 1] == 'S' ) {
                if ( s[i - 1] == 'o' ) {
                    if ( t[i - 2] == 'S' ) t += 'S';
                    else t += 'W';
                } else {
                    if ( t[i - 2] == 'S' ) t += 'W';
                    else t += 'S';
                }
            } else {
                if ( s[i - 1] == 'o' ) {
                    if ( t[i - 2] == 'S' ) t += 'W';
                    else t += 'S';
                } else {
                    if ( t[i - 2] == 'S' ) t += 'S';
                    else t += 'W';
                }
            }
        }
        if ( t[0] == t[n] && t[1] == t[n + 1] ) {
            for ( int i = 0 ; i < n ; i++ ) cout << t[i];
            return 0;
        }
    }
    cout << -1;
}