#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int n ;
	cin>>n ;

	vector<int> a(n) ;

	for(int i=0;i<n;i++){
		cin>>a[i] ;
	}	
	
	int ans=0 ;
	int x=0 ;

	for(int i=0;i<n;i++){
		ans=(ans+(ll)a[i]*x)%mod ;
		x=(x+a[i])%mod  ;
	}

	cout<<ans;

}
int main(){
	
	int y ;

	y=1 ;
	//cin>>y ;

	while(y--)
	{	
		solve() ;
	}

}