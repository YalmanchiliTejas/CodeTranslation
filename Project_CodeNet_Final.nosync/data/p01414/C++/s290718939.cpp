#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define reep(i,a,b) for(int i=a; i<b; i++)
#define fi first
#define se second
using pii = pair<int,int>;

int table[4][4];

bool inside(int a, int b){
	return 0<=a&&a<4&&0<=b&&b<4;
}

int calc(vector<vector<int>> vv){
	int state = 0;
	rep(i,4){
		rep(j,4){
			if(vv[i][j]){
				state += 1<<(i*4+j);
			}
		}
	}
	return state;
}

int main(){
	int n;
	cin>>n;
	vector<pii> v(n);
	rep(i,n){
		cin>>v[i].fi>>v[i].se;
	}
	vector<pair<pii,pii>> w;
	int dx[] = {1,1,-1,-1};
	int dy[] = {1,-1,1,-1};
	rep(i,4){
		rep(j,4){
			rep(k,n){
				rep(l,4){
					pii lu(i,j);
					pii rd(max(0,min(i+dx[l]*(v[k].fi-1), 3)), max(0,min(j+dy[l]*(v[k].se-1), 3)));
					w.push_back(minmax(lu,rd));
				}
			}
		}
	} 
	sort(w.begin(), w.end());
	w.erase(unique(w.begin(), w.end()), w.end());
	rep(i,4){
		rep(j,4){
			char t;
			cin>>t;
			rep(k,3){
				if(t == "RGB"[k]){
					table[i][j] = k;
				}
			}
		}
	}
	vector<int> dp(1<<16,1e9);
	dp[0] = 0;
	rep(i,1<<16){
		if(dp[i]>1e8) continue;
		vector<vector<int>> vv(4,vector<int>(4));
		rep(j,16){
			if(i&(1<<j)){
				vv[j/4][j%4] = 1;
			}
		}
		for(auto x: w){
			bool ok = true;
			int color = -1;
			reep(k,x.fi.fi, x.se.fi+1){
				reep(l,x.fi.se, x.se.se+1){
					if(vv[k][l]==0){
						if(color == -1) color = table[k][l];
						else if(color != table[k][l]) ok = false;
					}
				}
				if(!ok) break;
			}
			if(ok){
				// auto tmp = vv;
				int tmp = i;
				reep(k,x.fi.fi, x.se.fi+1){
					reep(l,x.fi.se, x.se.se+1){
						if(vv[k][l]==0){
							tmp += 1<<((k)*4+l);
						}
					}
				}
				dp[tmp] = min(dp[tmp], dp[i]+1);
			}
		}
	}
	cout<<dp[(1<<16)-1]<<endl;
}