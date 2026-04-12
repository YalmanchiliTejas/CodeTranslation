#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,k,ans;
int main(){
	scanf("%d%d",&n,&k);
	for(int b=k+1;b<=n;b++){
		ans+=n/b*(b-k);
		int remain=n%b;
		if(remain>=k){
			if(k)ans+=remain-k+1;
			else ans+=remain-k;
		}
	}
	printf("%lld",ans);
	return 0;
}