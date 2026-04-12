#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;

const LL NN=100*1000+1;
const LL mod=1000*1000*1000+7;
LL U=1LL<<60;
vector<P> path[NN];
LL dist[NN];
LL dist2[NN];
LL num[NN];
LL num2[NN];

int main() {
	int N,M;
	cin >> N >> M;
	int S,T;
	cin >> S >> T;
	S--;T--;
	for(int i=0;i<M;i++){
		int u,v,d;
		cin >> u >> v >> d;
		u--;
		v--;
		path[u].push_back(P(v,d));
		path[v].push_back(P(u,d));
	}
	priority_queue<P,vector<P>,greater<P> > pq;
	for(int i=0;i<N;i++){
		dist[i]=dist2[i]=U;
		num[i]=0;
	}
	pq.push(P(0,S));
	dist[S]=0;
	vector<int> order;
	while(pq.size()){
		int p=pq.top().second;
		LL d=pq.top().first;
		pq.pop();
		if(dist[p]<d)continue;
		order.push_back(p);
		//cout << p << endl;
		for(auto n:path[p]){
			if(dist[n.first]>n.second+d){
				dist[n.first]=n.second+d;
				pq.push(P(n.second+d,n.first));
			}
		}
	}

	pq.push(P(0,T));
	dist2[T]=0;
	vector<int> order2;
	while(pq.size()){
		int p=pq.top().second;
		LL d=pq.top().first;
		pq.pop();
		if(dist2[p]<d)continue;
		order2.push_back(p);
		for(auto n:path[p]){
			if(dist2[n.first]>n.second+d){
				dist2[n.first]=n.second+d;
				pq.push(P(n.second+d,n.first));
			}
		}
	}
	LL t=dist[T];
	num[S]=1;
	num2[T]=1;
	vector<LL> vs;
	for(int r:order2){
		for(auto p:path[r]){
			if(dist2[p.first]==dist2[r]+p.second){
				num2[p.first]+=num2[r];
				num2[p.first]%=mod;
			}
		}
	}
	LL ng=0;
	for(int r:order){
		if(dist[r]*2==t&&dist[r]+dist2[r]==t){
			ng+=num[r]*num[r]%mod*num2[r]%mod*num2[r]%mod;
			ng%=mod;
		}
		//cout << r << ": " << dist[r] << endl;
		for(auto p:path[r]){
			if(dist[p.first]==dist[r]+p.second){
				num[p.first]+=num[r];
				num[p.first]%=mod;
				if(dist[r]*2<t&&t<dist[p.first]*2&&dist[r]+dist2[r]==t&&dist[p.first]+dist2[p.first]==t){
					ng+=num[r]*num[r]%mod*num2[p.first]%mod*num2[p.first]%mod;
					ng%=mod;
				}
			}
		}
	}
	cout << (num[T]*num[T]%mod+mod-ng)%mod << endl;

	return 0;
}

