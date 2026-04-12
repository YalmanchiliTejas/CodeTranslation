#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <sstream>

using namespace std;

#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) (EQ((a).real(),(b).real()) && EQ((a).imag(),(b).imag()))

typedef complex<double> P;
typedef long long ll;

const int MAX_SIZE = 10000;
const int INF = 1000000000;

struct edge{
	int to;
	int cap;
	int num;
};

vector<edge> G[300];
bool isArrival[300];
int costs[50000];
int n,m;

void dfs(int k,int b1,int b2){
	if(isArrival[k])
		return;
	isArrival[k] = true;
	for(int i = 0; i < G[k].size(); i++){
		edge e = G[k][i];
		if(!(e.num == b1 || e.num == b2))
			dfs(e.to,b1,b2);
	}
}


void solve(){
	while(cin >> n >> m && !(n == 0 && m == 0)){
		// edgeÌîñðNA
		for(int i = 0; i < 300; i++){
			G[i].clear();
		}
		// RXge[uðú»
		fill(costs,costs+50000,0);
		int from,to,cap;
		int num = 0;
		int minus = 0;

		for(int i = 0; i < m; i++){
			cin >> from >> to >> cap;
			edge e;
			e.to = to;
			e.cap = cap;
			// RXgª0ÈºÈçA©Èç¸»ÌÓðí·é
			if(e.cap <= 0){
				minus += e.cap;
			}
			else{
				// from -> toÌûüÉGbWðÇÁ
				// GbWÉÔðÂ¯Ä¨­
				e.num = num;
				costs[num] = cap;
				num++;
				G[from].push_back(e);
				// to->fromÌûüÉGbWðÇÁ
				e.to = from;
				G[to].push_back(e);
			}
		}
		// 1,2{Á·üðßÄSTõ
		int minCost = INF;
		fill(isArrival,isArrival+n,false);
		dfs(0,-1,-1);
		if(count(isArrival,isArrival+n,true) != n){
			minCost = min(minCost,0);
		}


		if(num >= 1){
			for(int i = 0; i < num; i++){
				int sumCost = costs[i];
				// ·×ÄÌ_ÉGbWªqªÁÄ¢È¯êÎAÅ¬lðXV
				fill(isArrival,isArrival+n,false);
				dfs(0,i,i);
				if(count(isArrival,isArrival+n,true) != n){
					minCost = min(minCost,sumCost);
				}
			}
		}
		if(num >= 2){
			for(int i = 0; i < num-1; i++){
				for(int j = i+1; j < num; j++){
					int sumCost = costs[i] + costs[j];
					// ·×ÄÌ_ÉGbWªqªÁÄ¢È¯êÎAÅ¬lðXV
					fill(isArrival,isArrival+n,false);
					dfs(0,i,j);
					if(count(isArrival,isArrival+n,true) != n){
						minCost = min(minCost,sumCost);
					}
				}
			}
		}
		if(minCost == INF)
			cout << 0 + minus << endl;
		else
			cout << minCost + minus << endl;
	}
}

int main(){
	solve();
	//while(cin >> n >> m && !(n == 0 && m == 0)){
	//	int minminCost = INF;
	//	int from,to,cap;

	//	vector<int> froms,tos,caps;
	//	int minus = 0;
	//	for(int i = 0; i < m; i++){
	//		cin >> from >> to >> cap;

	//		if(cap <= 0)
	//			minus+=(cap);
	//		else{
	//			froms.push_back(from);
	//			tos.push_back(to);
	//			caps.push_back(cap);
	//		}
	//	}
	//	for(int i = 0; i < n; i++){
	//		for(int j = i+1; j < n; j++){
	//			// Å¬JbgâèðÆ­
	//			int minCost = INF;

	//			for(int k = 0; k < n; k++)
	//				G[k].clear();
	//			for(int k = 0; k < froms.size(); k++){
	//				add_edge(froms[k],tos[k],caps[k]);		
	//			}
	//			minCost = max_flow(i,j);
	//			for(int k = 0; k < n; k++)
	//				G[k].clear();
	//			for(int k = 0; k < froms.size(); k++){
	//				add_edge(froms[k],tos[k],caps[k]);		
	//			}
	//			minCost = max(minCost,max_flow(j,i));

	//			minminCost = min(minminCost,minCost);
	//		}
	//	}
	//	cout << minminCost+minus << endl;
	//}


	return 0;
}