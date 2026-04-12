#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define INF 1e18
#define MOD 1000000007
#define N 1000005
#define BB(V) V[V.size()-2]
#define ex(V) return printf(V),0
using namespace std;
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	if(k==0){
		printf("%lld",(ll)n*n);
		return 0;
	}
	ll ans=0;
	for(int i=k+1;i<=n;i++){
		ans+=((n+1)/i)*(i-k)+max((n+1)%i,k)-k;
	}
	printf("%lld",ans);
}