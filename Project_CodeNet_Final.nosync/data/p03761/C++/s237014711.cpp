#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
typedef long long ll;
 
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string s[n] = {};
	for ( int i = 0 ; i < n ; i++ ) cin >> s[i];
	for ( int i = 0 ; i < 26 ; i++ ) {
        char a = i + 'a';
        int b = 0 , c = 0;
        for ( int j = 0 ; j < n ; j++ ) {
            b = 0;
            for ( int k = 0 ; k < s[j].length() ; k++ ) {
                if ( s[j][k] == a ) b++;
            }
            if( j == 0 ) c = b;
            c = min( b , c );
        }
        for ( int j = 0 ; j < c ; j++ ) cout << a;
    }
	
}