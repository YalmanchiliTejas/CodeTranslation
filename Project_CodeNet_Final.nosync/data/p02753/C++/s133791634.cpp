#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define MOD 998244353
 
using namespace std;


int main(){
 
	ios_base::sync_with_stdio(false);
	//cin.tie(0);
	cout<<fixed<<setprecision(12);
	//memset(dp,-1,sizeof(dp));
	string s;
	cin>>s;
	int a=0;
	for(int i=0; i<3; i++){
		if(s[i] == 'A') a++;
	}

	if(a != 0 && a != 3) cout<<"Yes";
	else cout<<"No";

	

	return 0;
}
 