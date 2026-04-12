#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

#define int long long
#define endl "\n"

constexpr long long INF = (long long)1e18;
constexpr long long MOD = 1'000'000'007; 

struct fast_io {
	fast_io(){
		std::cin.tie(nullptr);
		std::ios::sync_with_stdio(false);
	};
} fio;

signed main(){
	cout<<fixed<<setprecision(10);
	
	int N, M, X;
	int ans = 0;
	vector<int> A;
	vector<vector<int>> table;
	vector<vector<int>> tables;

	cin>>N>>X>>M;
	
	table.resize(40, vector<int>(M));
	tables.resize(40, vector<int>(M));
	
	for(int j = 0; j < M; j++){
		table[0][j] = (j * j)% M;
		tables[0][j] = ((j * j)%M);
	}
	
	for(int i = 1; i < table.size(); i++){
		for(int j = 0; j < M; j++){
			table[i][j] = table[i-1][table[i-1][j]];
			tables[i][j] = tables[i-1][table[i-1][j]] + tables[i-1][j];
			// if(i <= 3)cout<<"i = "<<i<<" j = "<<j<<" tab = "<<table[i][j]<<" tabs = "<<tables[i][j]<<endl; 
		}
	}
	
	
	// N++;
	N--;;
	int now = X;
	
	// cout<<table[0][X]<<" "<<tables[0][X]<<endl;
	// cout<<table[1][X]<<" "<<tables[1][X]<<endl;
	// cout<<table[2][X]<<" "<<tables[2][X]<<endl;
	// cout<<table[3][X]<<" "<<tables[3][X]<<endl;
	
	for(int i = 0; i < table.size(); i++){
		if((N>>i)&1) {
			// cout<<i<<" now = "<<now<<endl;
			ans += tables[i][now];
			now = table[i][now];
		}
	}
	// cout<<now<<endl;
	cout<<ans+X<<endl;
	
	return 0;
}