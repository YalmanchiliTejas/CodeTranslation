//       Author: Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  acos(-1)
#define EPS (1e-10)
#define endl "\n"
#define SZ(v) (int)(v.size())
#define IO ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
typedef long long ll;
typedef long double ld;
 

 
ll MOD=1e9 + 7;
ll OO=1e10;
const int N=3e3 + 5,M=1e5 + 5;
int arr[N];
ll dp[N][N][2];


int n,m,k,cnt,SU,idx,len,MN,MX,T;
int l,r,mid;
int a,b,c;

ll Solve(int l,int r,bool player){
	
	if(l>r)
		return 0;
	
	ll &ret = dp[l][r][player];
	if(~ret)
		return ret;
	
	if(player)	
		ret = max(arr[l] + Solve(l+1,r,!player),arr[r] + Solve(l,r-1,!player));
	else
		ret = min(-arr[l] + Solve(l+1,r,!player),-arr[r] + Solve(l,r-1,!player));
	
	return ret;
}



int main(){
	IO
	
	memset(dp,-1,sizeof dp);
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>arr[i];
	
	cout<<Solve(0,n-1,1)<<endl;
		
	
	

}



