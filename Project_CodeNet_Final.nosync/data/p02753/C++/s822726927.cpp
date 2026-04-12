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
	
	string S;
	
	cin>>S;
	
	if(count(S.begin(), S.end(), 'A') == 0 ||count(S.begin(), S.end(), 'B') == 0) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	
	
	return 0;
}