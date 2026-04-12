#include <bits/stdc++.h>
using namespace std;


#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ll long long


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int h[20];
    int n;

    cin >> n;
    for ( int i = 0; i < n; i++ ) cin >> h[i];

    int qnt = 1;
    for ( int i = 1; i < n; i++ ) {
    	bool pos = true;
    	for ( int j = 0; j < i; j++ ) {
    		if ( h[j] > h[i] ) {
    			pos = false;
    			break;
    		}
    	}
    	if ( pos ) {
    		qnt++;
    	}
    }

    cout << qnt << endl;


    return 0;
}
