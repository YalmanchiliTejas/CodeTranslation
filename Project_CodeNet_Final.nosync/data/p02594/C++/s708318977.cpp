#pragma GCC optimize("Ofast")  
#include<bits/stdc++.h>
using namespace std;

#define ll 				long long
#define eb 				emplace_back
const long long 		MOD = 1e9 + 7;
#define rep(i,n) 		for (int (i) = 0; (i) < (n); (i)++) 
#define REP(i,k,n)  	for (int (i) = (k); (i) <= (n); (i)++) 
#define REPR(i,k,n) 	for (int (i) = (k); (i) >= (n); (i)--)
#define watch(x) 		cout << (#x) << " = " << (x) << endl
#define t(x)			int x; cin >> x; while(x--)

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	/*---- continue Coding ;----*/

	int n;
	cin >> n;
	if(n >= 30){
		cout << "Yes" << "\n";
	}else{
		cout << "No" << "\n";
	}
	
	/*---- break ;----*/

	cerr<<"Execution time: "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0;
}