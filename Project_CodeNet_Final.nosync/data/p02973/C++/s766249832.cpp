#include<bits/stdc++.h>

#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD=1e9+7;
const ll LINF=1e18;
const int INF=0x3f3f3f3f;
const int MAXN=100050;

int dp[MAXN];
bool cmp(int a,int b){
	return a>b;
}
void solve(int T){
	int n,tmp,siz=0;
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++){
		scanf("%d",&tmp);
		int l=1,r=n,mid;
		while(l<r){
			mid=(l+r)/2;
			if(dp[mid]<tmp){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		if(dp[l]==-1){
			siz++;
		}
		dp[l]=tmp;
	}
	printf("%d",siz);
}
signed main(){
	int t=1;
	//scanf("%d",&t); 
	for(int i=1;i<=t;i++){
		solve(i);
	}
}