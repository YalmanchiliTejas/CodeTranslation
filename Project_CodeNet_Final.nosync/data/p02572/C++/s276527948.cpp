#include <bits/stdc++.h>
using namespace std; 

#define rep(i,a,b) for(long long i = (a); i < (b); i++)
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
using ll = long long;


void solve() 
{
	int n;
	cin>>n;
	vector<int> v(n);
	rep(i,0,n){
		cin>>v[i];
	}
	ll sum=0;
	ll ans=0;
	ll MOD=1e9+7;
	for(int i=n-1;i>=0;i--){
		ans=(ans+(sum*v[i]))%MOD;
		sum=(sum+v[i])%MOD;
	}
	cout<<ans;
}

int  main(){
ll t;
t=1;
//cin>>t;
while(t--){
	
		solve();
		cout<<endl;

}
	
	
			
}