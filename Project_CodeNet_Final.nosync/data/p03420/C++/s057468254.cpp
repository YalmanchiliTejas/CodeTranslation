#include <bits/stdc++.h>
using namespace std;
int n,k; long long ans;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=k+1,j;i<=n;++i){
		/*(k~i-1)
		(k~i-1)+i
		(k~i-1)+2i   2i+k~3i-1
		a%i>=k*/
		
		for (j=0;;j+=i){
			//j+k~j+i-1
			if (j+k>n) break;
			if (j+i-1>n){
				ans+=n-j-k+1;
				break;
			}else ans+=i-k;
		}
		if (k==0) --ans;
	}
	printf("%lld\n",ans);
	return 0; 
}