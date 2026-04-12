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
	
	int N;
    vector<int> A;
    int sum = 0;
    int ans = 0;
    
    cin>>N;
    
    A.resize(N);
    
    
    for(int i = 0; i < N; i++){
        cin>>A[i];
        
        sum += A[i];
        sum %= MOD;
    }
	
    for(int i = 0; i < N; i++){
        
        sum = (sum  + MOD - A[i]%MOD) % MOD;
        ans += sum * A[i] % MOD;
        ans %= MOD;
        
    }
	
    cout<<ans<<endl;
    
	return 0;
}