#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
	int h,w;cin>>h>>w;
	char grid[h][w];
	rep(i,h) rep(j,w) cin>>grid[i][j];

	rep(i,w){
		int cnt=0;
		rep(j,h) {
			if(grid[j][i]=='.') cnt++;
		}
		if(cnt==h){
			rep(j,h) grid[j][i]='2';
		}
	}
	rep(i,h){
		int cnt=0;
		rep(j,w) {
			if(grid[i][j]=='.'||grid[i][j]=='2') cnt++;
		}
		if(cnt==w){
			rep(j,w) grid[i][j]='1';
		}
	}
/*	
	rep(i,h){
		rep(j,w) cout<<grid[i][j];
		cout<<"\n";
	}
*/
	rep(i,h){
		int chk=0;
		rep(j,w){
			if(grid[i][j]=='1') {
				chk=1;
				break;
			}
			else if(grid[i][j]=='2'){
				chk=2;
				continue;
			}
			else cout<<grid[i][j];
		}
		if(chk==1&&i!=h-1) continue;
		else cout<<"\n";
	}
}