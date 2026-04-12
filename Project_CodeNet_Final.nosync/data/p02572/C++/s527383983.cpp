#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
const int MOD = 1e9+7;
long long n,a[N],s[N];
long long res=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		s[i]%=MOD;
	} 
	for(int i=1;i<=n;i++){
		res+=1LL*a[i]*(s[n]-s[i]+MOD)%MOD;
		res%=MOD;
	}
	printf("%lld\n",res);
}