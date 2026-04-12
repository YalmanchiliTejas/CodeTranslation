#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
const int    INF = 100000000;
const double EPS = 1e-10;
const int    MOD = 1000000007;
using namespace std;
typedef pair<int,int> P;

int n;
int h[20], w[20];
int brd[7][7];
int dp[(1<<16)];

int main(){
	rep(i,(1<<16)) dp[i] = INF;
	dp[0] = 0;
	cin >> n;
	rep(i,n) cin >> h[i] >> w[i];
	for(int i = 3; i < 7; i++) for(int j = 3; j < 7; j++){
		char c;
		cin >> c;
		if(c == 'R') brd[i][j] = 1;
		if(c == 'G') brd[i][j] = 2;
		if(c == 'B') brd[i][j] = 3;
	}
	queue<int> que;
	que.push(0);
	while(!que.empty()){
		int q = que.front();
		int Q = q;
		que.pop();
		int b[7][7];
		rep(i,7) rep(j,7) b[i][j] = 0;
		for(int i = 3; i < 7; i++) for(int j = 3; j < 7; j++){
			b[i][j] = (q&1);
			q >>= 1;
		}
		q = Q;
		rep(i,n){
			rep(j,7){
				rep(k,7){
					if(j+h[i] < 3 || k+w[i] < 3) continue;
					//{
						int l = -1;
						rep(hh,h[i]){
							if(j+hh >= 7) continue;
							rep(ww,w[i]){
								if(k+ww >= 7) continue;
								if(b[j+hh][k+ww] == 0 && brd[j+hh][k+ww] != 0){
									l = brd[j+hh][k+ww];
									break;
								}
							}
						}
						if(l == -1) continue;
						bool ok = true;
						rep(hh,h[i]){
							if(j+hh >= 7) continue;
							rep(ww,w[i]){
								if(k+ww >= 7) continue;
								if(b[j+hh][k+ww] == 0 && brd[j+hh][k+ww] != 0 && brd[j+hh][k+ww] != l){
									ok = false;
									break;
								}
							}
							if(!ok) break;
						}
						if(!ok) continue;
						int x = 0;
						for(int hh = 6; hh >= 3; hh--){
							for(int ww = 6; ww >= 3; ww--){
								if(j <= hh && hh < j+h[i] && k <= ww && ww < k+w[i]){
									x *= 2;
									x += 1;
								} else{
									x *= 2;
									x += b[hh][ww];
								}
							}
						}
						if(dp[x] > dp[q]+1){
							dp[x] = dp[q]+1;
							que.push(x);
							if(x == (1<<16)-1){
								queue<int> emp;
								swap(que,emp);
							}
						}
					//}
				}
			}
		}
	}
	cout << dp[(1<<16)-1] << endl;
}