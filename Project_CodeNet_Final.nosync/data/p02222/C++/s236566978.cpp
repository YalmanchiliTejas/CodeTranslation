#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

vector<int> v;
int banned = 2;

void dfs1(auto &E,int now,int parent){
	int maxi = 0;
	for(int i=0;i<E[now].size();i++){
		int to = E[now][i];
		if(to==parent)continue;
		dfs1(E,to,now);
		maxi = max(maxi,v[to]);
	}
	
	v[now] = maxi+1;
}

void dfs2(auto &E,int now,int parent,int X){
	vector<pair<int,int>> P;
	for(int i=0;i<E[now].size();i++){
		int to = E[now][i];
		if(to==parent)continue;
		P.emplace_back(v[to],to);
	}
	
	P.emplace_back(X,parent);
	
	sort(P.rbegin(),P.rend());
	
	if(P.size()>=3&&P[2].first>=1){
		int A = P[0].first;
		int B = P[2].first;
		//cout<<now<<':'<<A<<endl;
		if(A!=B){
			banned = max(banned,A+B);
		}
		else{
			banned = max(banned,A+B-1);
		}
	}
	
	
	sort(P.rbegin(),P.rend());
	
	for(int i=0;i<E[now].size();i++){
		int to = E[now][i];
		if(to==parent)continue;
		if(P[0].second!=to)dfs2(E,to,now,P[0].first+1);
		else dfs2(E,to,now,P[1].first+1);
	}
}

int main(){
    
	int N;
	cin>>N;
	
	vector<vector<int>> E(N,vector<int>());
	
	for(int i=0;i<N-1;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	v.resize(N,1);
	
	dfs1(E,0,-1);
	
	dfs2(E,0,-1,0);
	
	string ans(N,'1');
	
	for(int i=2;i<banned;i++){
		ans[i] = '0';
	}
	
	cout<<ans<<endl;
	
    return 0;
}

