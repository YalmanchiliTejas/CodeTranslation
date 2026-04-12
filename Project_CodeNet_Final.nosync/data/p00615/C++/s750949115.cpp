#include<iostream>
#include<algorithm>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
	int n, m, t[20001];
	while(cin >> n >> m, n||m){
		rep(i,n)	cin >> t[i];
		rep(i,m)	cin >> t[i+n];
		sort( t, t+n+m );
		int mDif = t[0];
		rep(i,n+m-1){
			if( t[i+1]-t[i] > mDif )
				mDif = t[i+1]-t[i];
		}
		cout << mDif << endl;
	}
	return 0;
}