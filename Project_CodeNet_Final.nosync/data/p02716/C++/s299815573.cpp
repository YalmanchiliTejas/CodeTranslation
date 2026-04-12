//       Author: Mostafa Mounir Shehab
 
#include <bits/stdc++.h>
using namespace std;
 
#define PI  3.14159265  // PI = acos(-1)
#define EPS (1e-10)
#define endl "\n"
#define SZ(v) (int)(v.size())
typedef long long ll;
typedef long double ld;
//template <class Type>
 
 
void Fast(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
}
 
inline int D(){
	int t;
	scanf("%d",&t);
	return t;
}
inline ll llD(){
	ll t;
	scanf("%lld",&t);
	return t;
}
 

 

ll MOD=1e9 + 7; 
const int N=2e5 + 4;
ll arr[N];
unordered_map<int,ll> dp[N];
ll OO=1e16;
 
 
ll n,m,k,cnt,SU,idx,len,MN,MX,T,prime;
ll l,r,mid;
ll a,b,c,d;
vector<int> vec,v;
string str,s;

ll Solve(int idx,int len){
	
	if((n-idx+1)/2 + len < n/2)
		return -OO;
	
	if(idx >= n)
		return len == n/2 ? 0 : -OO;
	
	if(dp[idx].count(len))
		return dp[idx][len];


	ll ret = -OO;
	
	ret = max(ret,arr[idx] + Solve(idx+2,len+1));
	ret = max(ret,Solve(idx+1,len));
	
	return dp[idx][len] = ret;
	
}





int main(){

	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%lld",arr+i);
	
	printf("%lld\n",Solve(0,0));

	return 0;
}
 
 
 
 
 
 
 
 