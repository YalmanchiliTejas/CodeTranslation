#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define rep(i,n) for(int i = 0; i < (n); i++)
#define INF (long long)(1e18)
#define MOD (int)(1e9+7)

#define yn(f) (f?"Yes":"No")
#define YN(f) (f?"YES":"NO")

signed main(){
	cout<<fixed<<setprecision(7);
	
	
	int n;
	
	cin>>n;
	
	cout<<YN(n==7||n==5||n==3)<<endl;
	
	return 0;
}