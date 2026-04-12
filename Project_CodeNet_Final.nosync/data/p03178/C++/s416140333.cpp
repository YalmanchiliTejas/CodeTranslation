#include <bits/stdc++.h>
#include<string.h>
#define ll long long 
#include<vector>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int mod=1e9+7;
void add_self(int &a, int b){
	a+=b;
	if(a>=mod)
	a-=mod;
}
int main(){
	
	string k;
	int d;
	//cout<<"hey";
	cin>>k;
	cin>>d;
	
     int n=k.length();
     vector<vector<int> > dp=vector<vector<int> > (d,vector<int>(2));
     dp[0][1]=1;
     for(int where=0;where<n;where++){
     	//if it is tight my value willl go upto s[where] else my value will go upto 9
     	vector<vector<int> > new_dp=vector<vector<int> > (d,vector<int>(2));
     	for(int rem=0;rem<d;rem++)
     	{
          for(int tight=0;tight<2;tight++){
          	int my_limit=9;
          	if(tight) my_limit=k[where]-'0';
          	for(int my_digit=0;my_digit<=my_limit;my_digit++){
          		add_self(new_dp[(rem+my_digit)%d][tight&(my_digit==(k[where]-'0'))], dp[rem][tight]);
				 }
		  }
		 }
		 dp=new_dp;
		 /*cout<<where<<endl;
		 for(int i=0;i<d;i++){
		 	for(int tight=0;tight<2;tight++){
		 		cout<<dp[i][tight]<<" ";
			 }
			 cout<<endl;
		 }*/
	 }
	    ll ans=(dp[0][0]+dp[0][1]-1+mod)%mod;
	    cout<<ans;
	 	//cout<<(dp[0][0]+dp[0][1]-1)%mod;
		 
	}