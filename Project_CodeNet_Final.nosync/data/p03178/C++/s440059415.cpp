#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back 
#define mp make_pair
#define inf 2000000009
#define mod 1000000007
using namespace std;

int main()
{ 
  fast;
 string v;
 cin>>v;
 ll d;
 cin>>d;
 ll n=v.size();

 vector<vector<ll> > dp(d,vector<ll>(2,0));
 for(ll i=0;i<v[0]-48;i++)
 	dp[i%d][0]++;

 dp[(v[0]-48)%d][1]++;

 for(ll i=1;i<n;i++)
 {
 		vector<vector<ll> > temp(d,vector<ll>(2,0));

 		for(ll j=0;j<d;j++)
 		{
 			for(ll dig=0;dig<10;dig++)
 				(temp[(dig+j)%d][0]+=dp[j][0])%=mod;


 			for(ll dig=0;dig<=v[i]-48;dig++)
 			{
 				bool f=1;
 				if(dig<v[i]-48)
 					f=0;
 				(temp[(dig+j)%d][f]+=dp[j][1])%=mod;
 			}
 		}
 		dp=temp;
 }

cout<<(dp[0][0]+dp[0][1]-1+mod)%mod;

}

