
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n ;
	vector <int> mount(n);
	int dekai;
	dekai = 0;
	int mireru = 0;

	for ( int i = 0 ; i < n ; i++){
	cin >> mount[i] ;
	}

	for ( int i = 0 ; i < n ; i ++ ){
		if(dekai <= mount[i] ){
		mireru ++;
		dekai = mount[i];
		}
		else {
		continue;
		}
		}
		cout << mireru <<endl;
	}
	

 
