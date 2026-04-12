#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include<cmath>
#define pb push_back
#define ll long long
#define ull unsigned long long
#define deb(x) cerr<<#x<<" "<<x<<"\n"
#define debi cerr<<"hey sparky\n"
#define x first
#define y second
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define newline cout<<"\n"
#define yes cout<<"Yes"<<"\n"
#define no cout<<"No"<<"\n"
#define INF (ll)1e14+5
#define nax (ll)2e5+3
#define eps (double)1e-9
#define all(x) x.begin(),x.end()
 
using namespace std;
using namespace __gnu_pbds; 
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pdbs;
// look for  all edge cases
//search for a pattern
int n;
vector<ll> v(3003);

ll dp[3003][3003][3];

ll solve(int start,int end,int player){

	if(start > end){
		debi;
		return -1;
	}
	
	if(dp[start][end][player] != INF){
		return dp[start][end][player];
	}
	
	if(start == end){
		if(player == 1){
			
			dp[start][end][player] = v[start];
			return v[start];
		}
		else{
			dp[start][end][player] = v[start];
			return v[start];
		}
	}
	
	
	// case when player is taro 
	if(player == 1){
		ll val = 0;
		ll temp1 = v[start] - solve(start+1,end,2);
		ll temp2 = v[end] - solve(start,end-1,2);
		return dp[start][end][player] = max(temp1,temp2);
	}
	else{
		ll val= 0;
		ll temp1 = v[start] - solve(start+1,end,1);
		ll temp2 = v[end] - solve(start,end-1,1);
		
		return dp[start][end][player] = max(temp1,temp2);
	}
	
	
}



int main(){
	fast;
	cin >> n;
	//vector<ll> v(n+1); 
	
	for(int i = 0; i <=3002;i++){
		for(int j = 0 ; j<= 3002;j++){
			for(int k =0 ; k<3;++k){
				dp[i][j][k] = INF;
			}
		}
	}
	
	for(int i =1;i<=n;++i){
		 cin >> v[i];
	}
	ll ans = max(solve(1,n,1),solve(1,n,1));
	cout<<ans;
		
		
		
	return 0;
}

	
