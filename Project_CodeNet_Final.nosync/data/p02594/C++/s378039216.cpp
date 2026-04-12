//Atcoder series  of  7 contest 
//learning concepts through this 7 contest series
#include<bits/stdc++.h> 
#define int long long 
using namespace std; 
void solve(); 

int32_t  main() { 
	
	ios_base::sync_with_stdio(false);cin.tie(NULL); 

#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin); 
	freopen("error.txt", "w", stderr); 
	freopen("output.txt", "w", stdout); 
#endif 
	int t=1; 
	/*is Single Test case?*/
	while(t--) 
	{ 
		solve(); 
		cout<<"\n"; 
	} 

	cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl; 
	return 0; 
} 
void solve() { 
	int x ;
	cin>>x;
	if(x>=30) cout<<"Yes";
	else cout<<"No";
} 
