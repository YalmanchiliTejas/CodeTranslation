#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int main() {

    int n;
    cin >> n;

    int max_t = 0;
    vector<int> timing(n);
    for ( int i=0; i<n; ++i ) {
	cin >> timing[i];
	if ( timing[i] > max_t ) max_t = timing[i];
    }

    vector<int> divisor;
    for ( int i=1; i<=max_t>>1; ++i ) {
	if ( max_t%i == 0 ) divisor.push_back( i );
    }
    divisor.push_back( max_t );

    int adj = 0;
    for ( int t : timing ) {
	for ( int d : divisor ) {
	    if ( d >= t ) {
		adj += d - t;
		break;
	    }
	}
    }

    cout << adj << endl;
    
    return 0;
}

