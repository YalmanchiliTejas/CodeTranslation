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
	
	int X;
	
	cin>>X;
	
	if(X >= 30) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
	
	return 0;
}