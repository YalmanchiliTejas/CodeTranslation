#include <bits/stdc++.h>
#define ll long long
#define ff first 
#define ss second
#define MP make_pair
#define PB push_back
#define pri 1000000007
using namespace std;

int main() {
	
	string k;
	cin>>k;
	
	ll d;
	cin>>d;
	
	ll z=k.length();
	ll dp[z+1][d]={0};
	
	dp[z][0]=1;
	for(ll i=z-1;i>=0;i--){

		for(ll ze=0;ze<=9;ze++)
		  {
		  	
		  	for(ll za=0;za<d;za++)
		  	dp[i][(za+ze)%d]=(dp[i][(za+ze)%d]+dp[i+1][za])%pri;
		  	
		  }              
		
	                      }
		
						  
	ll za=0,ans=0;
	
	for(ll i=0;i<z;i++){
		      ll e=k[i]-'0';
	
		for(ll z=0;z<e;z++){
			ans=(ans+dp[i+1][(d-(za+z)%d)%d])%pri;}
		
		za=(za+e)%d;
						}
	if(za%d==0)ans++;	
		
	cout<<(ans-1+pri)%pri<<endl;
}