#include<bits/stdc++.h>
using namespace std;
#define ll long long int              //cout<<fixed<<setprecision(9)<<double value; 
#define INF 1000000000000000007
#define pb emplace_back 
#define md 1000000007
#define all(s) s.begin(),s.end()
typedef vector<int> vi;
ll ans=0;
int gh[101];
int d;
ll dp[101][4][2];
ll getsum(int idx,int n,int k,bool flag){
	if(idx>n)return (k==0);
	if(k==0){
		return 1;
	}
	if(dp[idx][k][flag]!=-1)return dp[idx][k][flag];
	int limit=9;
	if(!flag)limit=gh[idx];
	ll res=0;
	for(int i=0;i<=limit;i++){
		if(i<limit||flag){
			if(i>0)
			res+=getsum(idx+1,n,k-1,true);
			else
			res+=getsum(idx+1,n,k,true);
		}
		else{
			if(i>0)
			res+=getsum(idx+1,n,k-1,false);
			else
			res+=getsum(idx+1,n,k,false);
		}
	}
	return dp[idx][k][flag]=res;
}
void solve(){
	string b;
	cin>>b;
	cin>>d;
	for(int i=0;i<b.size();i++){
		gh[i+1]=b[i]-'0';
	}
	memset(dp,-1,sizeof dp);
    ll r=getsum(1,b.size(),d,0);
   cout<<r<<"\n";
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