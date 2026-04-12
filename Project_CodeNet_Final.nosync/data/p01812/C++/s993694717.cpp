#include <bits/stdc++.h>
#define REP(i,n,N) for(int i=n;i<N;i++)
#define p(S) cout<<(S)<<endl
typedef long long ll;
using namespace std;
const int inf=1e9;
int dp[(1<<16)];
bool visited[(1<<16)];
int main(){
	int N,M,K;
	cin>>N>>M>>K;
	int D[16];
	REP(i,0,M) {
		cin>>D[i];
		D[i]--;
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
	REP(i,0,(1<<M)) dp[i]=inf;
	REP(i,0,(1<<M)) visited[i]=false;
	dp[(1<<M)-1]=0;
	visited[(1<<M)-1]=true;
	
	queue<int> q;
	q.push((1<<M)-1);
	
	while(!q.empty()){
		int now=q.front();	q.pop();
		REP(j,0,K){
			int nstate=0;
			REP(i,0,M){
				if(now&(1<<i)) {
					int next=root[D[i]][j];
					int dr=-1;
					REP(k,0,M)	if(D[k]==next) dr=k;
					if(dr!=-1) nstate|=(1<<dr);
				}
			}
			if(!visited[nstate]) q.push(nstate);
			visited[nstate] = true;
			dp[nstate] = min(dp[nstate],dp[now]+1);
		}
	}
	p(dp[0]);
	return 0;
}