#include<iostream>
#include<vector>
#include<string>
#include<map>

#define REP(i,j,k) for( int i=j; i<k; i++ )
#define rep(i,j) REP(i,0,j)

using namespace std;

typedef long int LI;

int main(){
	
	int n,h[100];
	
	cin >> n;
	rep(i,n) cin >> h[i];
	
	int cnt = 1;
	
	REP(i,1,n){
		bool flg = true;
		rep(j,i){
			if(h[j]>h[i]){
				flg = false;
				break;
			}
		}
		if(flg) cnt++;
	}
	
	cout << cnt << endl;
	
	return 0;
	
}
