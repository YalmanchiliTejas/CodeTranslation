#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> bounce;

bool IsReachable() {
    int current = 0;
    for ( int i=0; i<n; ++i ) {
	if ( current < 10*i ) return false;
	current = max( current, 10*i + bounce[i] );
	if ( current >= 10*n ) return true;
    }
    return false;
}

int main() {

    cin >> n;
    bounce.resize( n );
    for ( int i=0; i<n; ++i ) cin >> bounce[i];
    if ( !IsReachable() ) {
	cout << "no" << endl;
	return 0;
    }
    
    reverse( bounce.begin(), bounce.end() );
    if ( !IsReachable() ) cout << "no" << endl;
    else cout << "yes" << endl;
    
    return 0;
}

