#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 10000000;
int cap[350][350];

int maximumFlow(int s, int t, int n){
	int res = 0;
	while(true){
		vector<int> prev(n,-1); prev[s] = s;
		queue<int> qu; qu.push(s);
		while(!qu.empty()&&prev[t]<0){
			int u = qu.front(); qu.pop();
			for(int i=0;i<n;i++){
				if(cap[u][i]>0&&prev[i]<0){
					prev[i] = u;
					qu.push(i);
				}
			}
		}
		if(prev[t]<0) return res;
		int inc = 10000000;
		for(int j=t;j!=prev[j];j=prev[j]) inc = min(inc, cap[prev[j]][j]);
		for(int j=t;j!=prev[j];j=prev[j]) cap[prev[j]][j] -= inc, cap[j][prev[j]] += inc;
		res += inc;
	}
	return res;
}

int main(){
	int H, W, C, M, Nw, Nc, Nm;
	while(cin >> H >> W >> C >> M >> Nw >> Nc >> Nm){
		if(H < 0) break;
		memset(cap,0,sizeof(cap));
		for(int i=1;i<=H;i++) cap[0][i] = 1;
		for(int i=1;i<=W;i++){
			int num; cin >> num;
			for(int j=0;j<num;j++){
				int pt; cin >> pt;
				cap[pt][H+i] = 1;
			}
			cap[H+i][H+W+i] = 1;
		}
		for(int i=1;i<=C;i++){
			int num; cin >> num;
			for(int j=0;j<num;j++){
				int pt; cin >> pt;
				cap[H+W+pt][H+2*W+i] = 1;
			}
			cap[H+2*W+i][H+2*W+C+i] = 1;
		}
		for(int i=1;i<=M;i++){
			int num; cin >> num;
			for(int j=0;j<num;j++){
				int pt; cin >> pt;
				cap[H+2*W+C+pt][H+2*W+2*C+i] = 1;
			}
			cap[H+2*W+2*C+i][H+2*W+2*C+M+6] = 1;
		}
		for(int i=1;i<=H;i++) cap[i][H+2*W+2*C+M+1] = 1;
		cap[H+2*W+2*C+M+1][H+2*W+2*C+M+2] = Nw;
		for(int i=1;i<=C;i++) cap[H+2*W+2*C+M+2][H+2*W+i] = 1;
		for(int i=1;i<=W;i++)
			cap[H+W+i][H+2*W+2*C+M+3] = 1;
		cap[H+2*W+2*C+M+3][H+2*W+2*C+M+4] = Nc;
		for(int i=1;i<=M;i++) cap[H+2*W+2*C+M+4][H+2*W+2*C+i] = 1;
		for(int i=1;i<=C;i++)
			cap[H+2*W+C+i][H+2*W+2*C+M+5] = 1;
		cap[H+2*W+2*C+M+5][H+2*W+2*C+M+6] = Nm;
		cout << maximumFlow(0, H+2*W+2*C+M+6, H+2*W+2*C+M+7) << endl;
	}
}