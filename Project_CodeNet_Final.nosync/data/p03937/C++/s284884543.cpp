#include <bits/stdc++.h>
using namespace std;

int main() {

    int h,w;
    cin >> h >> w;

    int hei[h] ={};
    int wid[w] ={};
    for(int i=0; i<h; i++) {
	string s; cin >> s;
	for(int j=0; j<w; j++) {
	    if( s[j] == '#' ) {
		hei[i]++;
		wid[j]++;
	    }
	}
    }

    int sum=0;
    for(int i=0; i<h; i++) {
	if( hei[i] == 0 ) {
	    cout << "Impossible" << endl;
	    return 0;
	}
	sum += hei[i];
    }
    for(int i=0; i<w; i++){
	if( wid[i] == 0 ) {
	    cout << "Impossible" << endl;
	    return 0;
	}
    }
    if( sum != h+w-1 ) {
	cout << "Impossible" << endl;
	return 0;
    }
    cout << "Possible" << endl;
    return 0;
    
}
