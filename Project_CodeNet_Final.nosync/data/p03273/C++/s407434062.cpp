#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int h,w;
	cin >> h >> w;
	char g[105][105];
	rep(i,h) rep(j,w) cin >> g[i][j];
	
	rep(i,h){
		rep(j,w){
			if(g[i][j] == '.'){
				bool exist = false;
				rep(k,h){
					if(g[k][j] == '#') exist = true;
				}
				if(!exist){
					rep(k,h){
						g[k][j] = '0';
					}
				}
				exist = false;
				rep(k,w){
					if(g[i][k] == '#') exist = true;
				}
				if(!exist){
					rep(k,w){
						g[i][k] = '0';
					}
				}
			}
		}
	}
	rep(i,h){
		bool flag = false;
		rep(j,w){
			if(g[i][j] == '0') continue;
			flag = true;
			cout << g[i][j];
		}
		if(flag){
			cout << endl;
		}
	}
    return 0;
}

