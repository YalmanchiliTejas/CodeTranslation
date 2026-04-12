#include<bits/stdc++.h>
using namespace std;
long long n,k,ans=0,x,xx,c;
int main(){
	scanf("%lld%lld",&n,&k);
	for(int i=k+1;i<=n;i++){
		x = (i-k) * (n/i);
		xx = 0;
//		printf("%d ",x);
		if(n % i > 0){
			if(k == 0){
				c = 1;
			}
			else{
				c = k;
			}
			xx = (n % i) - c +1;
			if(xx < 0){
				xx = 0;
			}
		}
		x += xx;
		ans += x;
//		printf("%d %d %d\n",i,x,ans);
	}
	printf("%lld",ans);
}