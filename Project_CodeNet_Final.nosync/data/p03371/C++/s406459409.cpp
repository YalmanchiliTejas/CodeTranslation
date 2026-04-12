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
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int A, B, C;
	int X, Y, Z;
	int ans = INF;
	
	cin>>A>>B>>C;
	cin>>X>>Y;
	
	Z = max(X,Y)*2;
	
	for(int i = 0; i <= Z; i++){
		int a = max(0ll, X - i/2);
		int b = max(0ll, Y - i/2);
		int cost = i * C;
		// cout<<"i = "<<i<<" "<<a<<" "<<b<<endl;
		// cout<<"cost = "<<cost<<endl;
		
		cost += a * A;
		cost += b * B;
		
		// cout<<"cost = "<<cost<<endl;
		// cout<<"cost = "<<cost<<endl;
		ans = min(ans, cost);
	}
	
	cout<<ans<<endl;
	
	
	return 0;
}