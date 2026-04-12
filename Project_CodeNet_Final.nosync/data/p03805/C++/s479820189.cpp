#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define endl "\n"

const long long INF = (long long)1e18;
const long long MOD = 1'000'000'007; 

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}


signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int N, M;
	int con = 0;
	vector<vector<int>> G;
	vector<int> hoge;
	
	cin>>N>>M;
	
	G.resize(N, vector<int>(N));
	
	for(int i = 0; i < M; i++){
		int a, b;
		
		cin>>a>>b;
		a--, b--;
		
		G[a][b]++;
		G[b][a]++;
	}
	
	for(int i = 0; i < N; i++){
		hoge.push_back(i);
	}
	
	do {
		bool flag = true;
		
		for(int i = 1; i < N; i++){
			if(G[hoge[i-1]][hoge[i]] == 0){
				flag = false;
				break;
			}
		}
		
		if(flag) con++;
		
	} while(next_permutation(hoge.begin()+1, hoge.end()));
	
	cout<<con<<endl;
	
	return 0;
}