#include <bits/stdc++.h>
using namespace std;
#include "string"
#define endl '\n'
#define PI pair<int,int>
#define ff first
#define ss second
#define int long long 
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)

const int N=3333;
const int M=998244353;

int n,s;
int a[N],dp[N][N];

int okk(int id,int cur){
	if(cur==0)
		return n-id+2;
	if(id>n or cur<0)
		return 0;
	int &tmp = dp[id][cur];
	if(tmp != -1)
		return tmp;
	tmp=okk(id+1,cur);
	tmp+=okk(id+1,cur-a[id]);
	tmp%=M;
	return tmp;
}

int32_t main() { 
	boost;
 	cin>>n>>s;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(dp,-1,sizeof dp);
	int ans=0;

	for(int i=1;i<=n;i++){
		ans=(ans+okk(i,s))%M;
		ans+=M;ans%=M;
	}
	cout<<ans<<endl;
}		    