#include <bits/stdc++.h>
using namespace std;
#include "string"
#define endl '\n'
#define pi pair<int,int>
#define ff first
#define ss second
#define int long long 
#define boost ios_base::sync_with_stdio(false);cin.tie(nullptr)

const int N=2*1e5+1;
const int inf = 1e18;
int dp[N][3];
bool vis[N][3];

int n;
int a[N];

int solve(int id,int have){
	if(id>n){
		if(have<=1)
			return 0;
		return -inf;
	}
	
	int &tmp = dp[id][have];
	if(vis[id][have])
		return tmp;
	vis[id][have]=1;
	if(!have)
		tmp = solve(id+2,have)+a[id];
	else{
		tmp =solve(id+2,have)+a[id];
		tmp = max(tmp,solve(id+1,have-1));
	}
	return tmp;
}

int32_t main() { 
    boost;
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    int ans ;
    if(n%2)
    	ans = solve(1,2);
    else
    	ans = solve(1,1);
    cout<<ans<<endl;
}           



