#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);  
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define int long long
void test_case(){
	int x; cin>>x;
	if(x >= 30){
		cout<<"Yes"<<endl;
	}
	else cout<<"No"<<endl;
}
		
 
signed main(){
	IOS;
	int i = 1;
	int t=1; //cin>>t;
	while(t--){
		//cout<<"Case #"<<i<<": ";
		test_case();
		i++;
	}
}
