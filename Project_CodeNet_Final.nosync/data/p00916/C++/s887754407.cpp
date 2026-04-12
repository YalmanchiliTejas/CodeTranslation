#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0 ; i < n ; i++)


long long color[300][300];
int done[300][300];
int ans;	
long long col;
int dfs(int x,int y){
	if( x < 0 || x >= 300 || y >= 300 || y < 0 ) return 0;
	if( col != color[x][y] )  return 0;
	if( done[x][y]++ ) return 0;
	dfs(x-1,y);
	dfs(x,y-1);
	dfs(x+1,y);
	dfs(x,y+1);
	
}
int main(){
	int n;
	while(cin >> n&&n){
		ans = 0;
		rep(i,300)rep(j,300) color[i][j]=0,done[i][j]=0;
		vector<int> l(n),t(n),r(n),b(n);
		vector<int> ux,uy;
		
		rep(i,n) {
			cin >> l[i] >> t[i] >> r[i] >> b[i];
			for(int j = -1 ; j <= 1 ; j++) ux.push_back(j+l[i]);
			for(int j = -1 ; j <= 1 ; j++) ux.push_back(j+r[i]);
			for(int j = -1 ; j <= 1 ; j++) uy.push_back(j+t[i]);
			for(int j = -1 ; j <= 1 ; j++) uy.push_back(j+b[i]);
			
		}
		sort(ux.begin(),ux.end());
		sort(uy.begin(),uy.end());
		ux.erase(unique(ux.begin(),ux.end()),ux.end());
		uy.erase(unique(uy.begin(),uy.end()),uy.end());
		rep(i,n){
			l[i] = lower_bound(ux.begin(),ux.end(),l[i]) - ux.begin();
			r[i] = lower_bound(ux.begin(),ux.end(),r[i]) - ux.begin();
			t[i] = lower_bound(uy.begin(),uy.end(),t[i]) - uy.begin();
			b[i] = lower_bound(uy.begin(),uy.end(),b[i]) - uy.begin();
			for(int x = l[i] ; x < r[i] ; x++)
				for(int y = b[i] ; y < t[i] ; y++)
					color[x][y] |= 1ll<<i;
		}

		for(int i = 0 ; i < 300 ; i++){
			for(int j = 0 ; j < 300 ; j++){
				if( !done[i][j] ){
					col = color[i][j];
					ans++;
					dfs(i,j);
				}
			}
		}
		cout << ans << endl;
	}

	
}