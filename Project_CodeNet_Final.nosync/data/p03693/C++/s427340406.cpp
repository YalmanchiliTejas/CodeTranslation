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
	
	int a, b, c;
	int d;
	
	cin>>a>>b>>c;
	
	d = a * 100 + b * 10 + c;
	
	if(d%4 == 0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}