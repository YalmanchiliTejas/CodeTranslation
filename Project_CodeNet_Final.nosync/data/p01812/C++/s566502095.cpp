#include <bits/stdc++.h>
#define REP(i,n,N) for(int i=n;i<N;i++)
#define p(S) cout<<(S)<<endl
typedef long long ll;
using namespace std;
const int inf=1e9;
int drdp[(1<<16)];
int main(){
	int N,M,K;
	cin>>N>>M>>K;
	int D[16];
	int isD[101]={};
	REP(i,0,M) {
		cin>>D[i];
		D[i]--;
		isD[D[i]]=(1<<i);
	}
	vector<int> root[110];
	int a;
	REP(i,0,N){
		REP(j,0,K){
			cin>>a;
			a--;
			root[i].push_back(a);
		}
	}
	REP(i,0,(1<<M)) drdp[i]=inf;
	drdp[(1<<M)-1]=0;
	queue<int> q;
	q.push((1<<M)-1);
	//bfs
	while(!q.empty()){
		int now=q.front();	q.pop();
		if(drdp[0] != inf) break;
		REP(j,0,K){
			int ns=0;
			REP(i,0,M){
				if(now&(1<<i)) {
					//next room is dark or not
					int next = root[D[i]][j];
					if(isD[next]>0)
						ns |= isD[next];
				}
			}
			if(drdp[ns]==inf) {
				drdp[ns] = drdp[now]+1;
				q.push(ns);
			}
		}
	}
	p(drdp[0]);
	return 0;
}