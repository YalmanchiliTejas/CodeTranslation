#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
const int mod=1e9+7;
int n,m,i,lst,dp[200005],s[200005],f[200005][2],tmp,mi=0x3f3f3f3f,l;
string st;
int main(){
	cin>>n>>m;
	cin>>st;
	st=" "+st;
	i=1;lst=1;
	while(i<=m){
		if(st[i]!=st[i-1]){
			if(st[i]!=st[1]){
				if(lst==1||((i-lst)&1)){
					mi=min(mi,i-lst);
				}
			}
			else{
				lst=i;
			}
		}
		i++;
	}
	if(mi<0x3f3f3f3f){
		if(n&1){
			puts("0");
			return 0;
		}
		mi=mi/2+1;
		n/=2;
		l=1;
/*		s[1]=1;s[mi+1]+=mod-1;
		rep(i,n){
			tmp=(tmp+s[i])%mod;
			dp[i]=tmp;
			s[min(n,i+1)]=(s[min(n,i+1)]+dp[i])%mod;
			s[min(n,i+mi)+1]=(s[min(n,i+mi)+1]+mod-dp[i])%mod;
		}
		cout<<dp[n]<<endl;*/
	}
	else{
		l=2;
	}
	for(i=l;i<=n;i++){
		dp[i]=(s[i-l]+(i>mi?-s[i-mi-1]:(3ll-l)*i))%mod;
		s[i]=(s[i-1]+dp[i])%mod;
	}
	cout<<(dp[n]+l-1+mod)%mod<<endl;
	return 0;
}