#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1e9;

int main(){
	int n;
	cin >> n;
	vector<int> h(n),w(n);
	for(int i=0; i<n; i++) cin >> h[i] >> w[i];
	vector<vector<char> > c(4, vector<char>(4));
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cin >> c[i][j];
		}
	}
	
	vector<int> dp(1<<16, inf);
	dp[0] = 0;
	for(int i=0; i<(1<<16); i++){
		if(dp[i] == inf) continue;
		for(int s=0; s<n; s++){
			for(int y=1-h[s]; y<=2+h[s]; y++){
				for(int x=1-w[s]; x<=2+w[s]; x++){
					char color = 0;
					int newidx = i;
					for(int j=0; j<h[s]; j++){
						for(int k=0; k<w[s]; k++){
							int ny=y+j, nx=x+k;
							if(ny<0 || 4<=ny || nx<0 || 4<=nx) continue;
							if((i & 1<<(4*ny +nx)) != 0) continue;
							if(color!=0 && color!=c[ny][nx]){
								color = 0;
								j = h[s];
								break;//j,k
							}
							color = c[ny][nx];
							newidx |= 1<<(4*ny +nx);
						}
					}
					if(color != 0){
						dp[newidx] = min(dp[newidx], dp[i]+1);
					}
				}
			}
		}
	}
	cout << dp[(1<<16) -1] << endl;
	return 0;
}
