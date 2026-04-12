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
	int n;
	cin >> n;
	string a,b;
	cin >> a;
  	a+=a[0];
	for ( int j = 0 ; j < 4 ; j++ ) {
		b.clear();
		if ( j == 0 ) b += 'S', b += 'S';
		if ( j == 1 ) b += 'S', b += 'W';
		if ( j == 2 ) b += 'W', b += 'S';
		if ( j == 3 ) b += 'W', b += 'W';  
		for ( int i = 2 ; i <= n + 1 ; i++ ) {
			if ( a[i-1] == 'o' ) {
				if ( b[i-1] == 'S') {
					if ( b[i-2] == 'W') b += 'W';
					else b += 'S';
				} 
				else {
					if (b[i-2] == 'W') b += 'S';
					else b += 'W'; 
				}
			}
			else {
				if ( b[i-1] == 'W') {
					if ( b[i-2] == 'W') b += 'W';
					else b += 'S';
				} 
				else {
					if (b[i-2] == 'W') b += 'S';
					else b += 'W'; 
				}
			}
		}
		if ( b[n] == b[0] && b[n+1] == b[1]) {
				cout << b.substr(0,n);
				return 0;
        }
	}
	cout << -1;
}