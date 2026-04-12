#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1e9+7, INF = 1e9, larg = 1e5;
int A,B,C,D,E,F,G,H,I,J,K,L,N,M,O,P,Q,R,S,T,U,V,W,X,Y,Z;
int max_value = 0, max_index = 0;
int min_value = INF, min_index = 0;

typedef pair<int, int> Po;
typedef long long ll;

int main() {
	cin >> H >> W;
	char m[100][100];
	rep(i, H){
		rep(j, W){
			cin >> m[i][j];
		}
	}

	rep(i, W){
		rep(j, H){
			if(m[j][i] == '#') break;
			if(j == H-1) {
				rep(k, H){
					m[k][i] = '!';
				}
			}
		}
	}

	rep(i, H){
		rep(j, W){
			if(m[i][j] == '#') break;
			if(j == W-1) {
				rep(k, W){
					m[i][k] = '*';
				}
			}
		}
	}

	rep(i, H){
		if(m[i][0]=='*') continue;
		rep(j, W){
			if(m[i][j]!='!'){
				cout << m[i][j];
			}
		}
		cout << endl;
	}
}