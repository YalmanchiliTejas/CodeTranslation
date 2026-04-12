#include <iostream>
#include <algorithm>
using namespace std;

int a[101];

int main(){
	int n;
	while( cin >> n, n ){
		for(int i=0 ; i < n ; i++ )
			cin >> a[i];
		int mx, mn;
		mx = mn = a[0];
		for(int i=1 ; i < n ; i++ ){
			mx = max( mx , a[i] );
			mn = min( mn , a[i] );
		}
		int s = 0;
		for(int i=0 ; i < n ; i++ ){
			if( a[i] == mn ){
				a[i] = 0;
				break;
			}
		}
		for(int i=0 ; i < n ; i++ ){
			if( a[i] == mx ){
				a[i] = 0;
				break;
			}
		}
		for(int i=0 ; i < n ; i++ ){
			s += a[i];
		}
		cout << s/(n-2) << endl;
	}
}