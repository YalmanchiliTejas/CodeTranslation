#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>
#include<bitset>
#include<queue>

using namespace std;

#define int long long
#define endl "\n"

constexpr long long INF = (long long)1e18;
constexpr long long MOD = 1'000'000'007; 

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}

int N, M, K;
vector<vector<int>> v;
vector<int> D, d;

int solve(){
	// cout<<"solve "<<endl;
	vector<vector<int>> G;
	G.resize(1<<M);
	
	for(int now = 0; now < 1<<M; now++){ //cout<<"now = "<<now<<endl;
		for(int i = 0; i < K; i++){
			int next = 0;
			for(int j = 0; j < M; j++){
				if(!(now&(1<<j))) continue;
				if(d[v[D[j]][i]]) next |= (1<<(d[v[D[j]][i]]-1));
			}
			if(now != next) {
				G[now].push_back(next);
				// cout<<"now -> next "<<now<<" -> "<<next<<endl;
			}
		}
	}
	
	queue<pair<int,int>> Q;
	vector<int> d((1<<M), INF);
	
	
	d[(1<<M)-1] = 0;
	Q.push({0, (1<<M)-1});
	
	while(Q.size()){
		pair<int,int> p = Q.front(); Q.pop();
		
		// cout<<"p.f = "<<p.first<<" p.s = "<<p.second<<endl;
		
		if(d[p.second] < p.first) continue;
		if(p.second == 0) break;
		
		for(int n : G[p.second]){
			if(d[n] > p.first + 1) {
				d[n] = p.first + 1;
				Q.push({d[n], n});
			}
		}
	}
	
	return d[0];
}

signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	
	
	cin>>N>>M>>K;
	
	D.resize(M);
	d.resize(N);
	v.resize(N, vector<int>(K));
	
	for(int i = 0; i < M; i++){
		cin>>D[i];
		D[i]--;
		d[D[i]] = i+1;
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < K; j++){
			cin>>v[i][j];
			v[i][j]--;
		}
	}
	
	cout<<solve()<<endl;
	
	
	return 0;
}
