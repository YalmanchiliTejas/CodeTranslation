//

//a%b>=k

//a=f*b+k
#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,K,ans;
void bf()
{
	LL ret=0;
	for(LL i=1;i<=n;i++)
	  for(LL j=1;j<=n;j++)
		if(i%j>=K) ret++;
	cout<<ret<<endl;
}
int main()
{
	cin>>n>>K;
	if(K==0) ans=n*n;
	else
	for(LL b=1;b<=n;b++){
		if(b<=K) continue;
		for(LL i=K;i<=n;i+=b){
			LL j=i+(b-K-1);
			//cout<<i<<' '<<j<<endl;
			if(j>n){
				ans+=(n-i+1); break;
			}
			ans+=(j-i+1);
		}
	}
	//bf();
	cout<<ans<<endl;
	return 0;
}
