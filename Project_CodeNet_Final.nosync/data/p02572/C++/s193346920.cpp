#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using ll = long long;
using namespace std;        
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define ar array
#define mod 1000000007

void solve(){
		int n;
		cin>>n;
		vector<int> v(n);
		for(auto &i:v) cin>>i;
		ll b=0,sum=0;
		for(int i=1;i<n;i++){
			b=(b+v[i-1])%mod;
			sum=(sum+v[i]*b)%mod;
		}
		cout<<sum<<endl;


	

}

int main(){
	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
//	freopen("input.txt",r,"stdin");
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}



