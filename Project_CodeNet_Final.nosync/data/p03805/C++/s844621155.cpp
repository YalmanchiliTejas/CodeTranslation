#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001


int main(){
	
	int N,M;
	cin>>N>>M;
	
	vector<vector<bool>> E(N,vector<bool>(N,false));
	
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		E[a][b]=true;
		E[b][a]=true;
	}
	
	vector<int> V(N);
	for(int i=0;i<N;i++)V[i]=i;
	
	int ans = 0;
	do{
		if(V[0]!=0)continue;
		bool f = true;
		for(int i=0;i<N-1;i++){
			if(E[V[i]][V[i+1]]==false){
				f=false;
			}
		}
		if(f)ans++;
	}
	while(next_permutation(V.begin(),V.end()));
	
	cout<<ans<<endl;
	
    return 0;
}

