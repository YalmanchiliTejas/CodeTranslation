#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x); i<=(y); i++)
#define ll long long
using namespace std;
int main(){
	int n,k; ll ans=0;
	scanf("%d%d",&n,&k);
	if (k==0) ans=(ll)n*n;
	else{
		rep (b,k+1,n){
			//a%b>=k
			ans+=(ll)(b-k)*(n/b)+max(0,n%b-k+1);
		}
	}
	printf("%lld\n",ans);
	return 0;
}