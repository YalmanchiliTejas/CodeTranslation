#include"bits/stdc++.h"
#include<unordered_set>
#include<unordered_map>
#include<random>
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

void end(){
	cout << -1 << endl;
	exit(0);
}

int N;
unsigned int S[500], T[500];
unsigned long long U[500], V[500];

unsigned long long ans[500][500] ={};

signed main(){
	cin >> N;
	rep(i, N) cin >> S[i];
	rep(i, N) cin >> T[i];
	rep(i, N) cin >> U[i];
	rep(i, N) cin >> V[i];

	rep(q, 64){
		int tmp[500][500] ={};
		rep(i, N){
			rep(j, N){
				tmp[i][j] = -1;
			}
		}

		// all 0 or all 1
		rep(i, N){
			if(S[i] == 0 && ((U[i]>>63-q)&1) == 1){
				rep(j, N){
					tmp[i][j] = 1;
				}
			}
			if(S[i] == 1 && ((U[i]>>63-q)&1) == 0){
				rep(j, N){
					tmp[i][j] = 0;
				}
			}
		}
		rep(j, N){
			if(T[j] == 0 && ((V[j]>>63-q)&1) == 1){
				rep(i, N){
					if(tmp[i][j] == 0) end();
					tmp[i][j] = 1;
				}
			}
			if(T[j] == 1 && ((V[j]>>63-q)&1) == 0){
				rep(i, N){
					if(tmp[i][j] == 1) end();
					tmp[i][j] = 0;
				}
			}
		}

		// part 0 x part 0 or part 1 x part 1
		rep(i, N){
			rep(j, N){
				if(S[i] == 0 && ((U[i]>>63-q)&1) == 0 && T[j] == 0 && ((V[j]>>63-q)&1) == 0){
					tmp[i][j] = 0;
				}
				if(S[i] == 1 && ((U[i]>>63-q)&1) == 1 && T[j] == 1 && ((V[j]>>63-q)&1) == 1){
					tmp[i][j] = 1;
				}
			}
		}

		// ume
		rep(i, N){
			if(S[i] == 0 && ((U[i]>>63-q)&1) == 1) continue;
			if(S[i] == 1 && ((U[i]>>63-q)&1) == 0) continue;
			bool flg = false;
			rep(j, N){
				if(S[i] == 0 && ((U[i]>>63-q)&1) == 0 && tmp[i][j] == 0) flg = true;
				if(S[i] == 1 && ((U[i]>>63-q)&1) == 1 && tmp[i][j] == 1) flg = true;
			}
			if(flg){
				rep(j, N){
					if(S[i] == 0 && ((U[i]>>63-q)&1) == 0 && tmp[i][j] == -1) tmp[i][j] = 1;
					if(S[i] == 1 && ((U[i]>>63-q)&1) == 1 && tmp[i][j] == -1) tmp[i][j] = 0;
				}
			}
		}
		rep(j, N){
			if(T[j] == 0 && ((V[j]>>63-q)&1) == 1) continue;
			if(T[j] == 1 && ((V[j]>>63-q)&1) == 0) continue;
			bool flg = false;
			rep(i, N){
				if(T[j] == 0 && ((V[j]>>63-q)&1) == 0 && tmp[i][j] == 0) flg = true;
				if(T[j] == 1 && ((V[j]>>63-q)&1) == 1 && tmp[i][j] == 1) flg = true;
			}
			if(flg){
				rep(i, N){
					if(T[j] == 0 && ((V[j]>>63-q)&1) == 0 && tmp[i][j] == -1) tmp[i][j] = 1;
					if(T[j] == 1 && ((V[j]>>63-q)&1) == 1 && tmp[i][j] == -1) tmp[i][j] = 0;
				}
			}
		}

		// check
		vector<int> zeroI, oneI;
		rep(i, N){
			if(S[i] == 0 && ((U[i]>>63-q)&1) == 1) continue;
			if(S[i] == 1 && ((U[i]>>63-q)&1) == 0) continue;
			bool flg = false;
			rep(j, N){
				if(S[i] == 0 && ((U[i]>>63-q)&1) == 0 && tmp[i][j] == 0) flg = true;
				if(S[i] == 1 && ((U[i]>>63-q)&1) == 1 && tmp[i][j] == 1) flg = true;
			}
			if(!flg){
				if(S[i] == 0 && ((U[i]>>63-q)&1) == 0) zeroI.pb(i);
				if(S[i] == 1 && ((U[i]>>63-q)&1) == 1) oneI.pb(i);
			}
		}
		vector<int> zeroJ, oneJ;
		rep(j, N){
			if(T[j] == 0 && ((V[j]>>63-q)&1) == 1) continue;
			if(T[j] == 1 && ((V[j]>>63-q)&1) == 0) continue;
			bool flg = false;
			rep(i, N){
				if(T[j] == 0 && ((V[j]>>63-q)&1) == 0 && tmp[i][j] == 0) flg = true;
				if(T[j] == 1 && ((V[j]>>63-q)&1) == 1 && tmp[i][j] == 1) flg = true;
			}
			if(!flg){
				if(T[j] == 0 && ((V[j]>>63-q)&1) == 0) zeroJ.pb(j);
				if(T[j] == 1 && ((V[j]>>63-q)&1) == 1) oneJ.pb(j);
			}
		}

		rep(i, zeroI.size()){
			rep(j, oneJ.size()){
				tmp[zeroI[i]][oneJ[j]] = (i+j)%2;
			}
		}
		rep(i, oneI.size()){
			rep(j, zeroJ.size()){
				tmp[oneI[i]][zeroJ[j]] = (i+j)%2;
			}
		}

		rep(i, N){
			rep(j, N){
				ans[i][j] = (ans[i][j]<<1) + tmp[i][j];
			}
		}
	}

	// last check
	rep(i, N){
		unsigned long long a = ans[i][0];
		unsigned long long o = ans[i][0];
		rep(j, N){
			a &= ans[i][j];
			o |= ans[i][j];
		}
		if(S[i] == 0 && a != U[i]) end();
		if(S[i] == 1 && o != U[i]) end();
	}
	rep(j, N){
		unsigned long long a = ans[0][j];
		unsigned long long o = ans[0][j];
		rep(i, N){
			a &= ans[i][j];
			o |= ans[i][j];
		}
		if(T[j] == 0 && a != V[j]) end();
		if(T[j] == 1 && o != V[j]) end();
	}

	rep(i, N){
		rep(j, N){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}