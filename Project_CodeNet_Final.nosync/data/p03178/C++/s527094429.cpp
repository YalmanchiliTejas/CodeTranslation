#include<bits/stdc++.h>
using namespace std;
#define ll long long int              //cout<<fixed<<setprecision(9)<<double value; 
#define INF 1000000000000000007
#define pb emplace_back 
#define md 1000000007
#define all(s) s.begin(),s.end()
typedef vector<int> vi;
ll ans=0;
int gh[10005];
int d;
ll dp[10005][102][2];
ll getsum(int idx,int n,int sum,bool flag){
	if(idx>n)return (sum==0);
	if(dp[idx][sum][flag]!=-1)return dp[idx][sum][flag];
	int limit=9;
	if(!flag)limit=gh[idx];
	ll res=0;
	for(int i=0;i<=limit;i++){
		if(i<limit||flag){
			res+=getsum(idx+1,n,(sum+i)%d,true);
		}
		else{
			res+=getsum(idx+1,n,(sum+i)%d,false);
		}
	}
	return dp[idx][sum][flag]=res%md;
}
void solve(){
	string b;
	cin>>b;
	cin>>d;
	for(int i=0;i<b.size();i++){
		gh[i+1]=b[i]-'0';
	}
	memset(dp,-1,sizeof dp);
    ll r=getsum(1,b.size(),0,0);
  
   cout<<(r-1+md)%md<<"\n";
}
int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
   int t=1;
  // cin>>t;
     while(t--){
     	solve();
	 }
     return 0;
}