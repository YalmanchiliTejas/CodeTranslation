#include<bits/stdc++.h>
using namespace std;
const long long mod=pow(10,9)+7;
int n;
long long a[200010],pre[200010];
int main(){
	 cin>>n;
	 for(int i=1;i<=n;i++){
	 	cin>>a[i];
	 	pre[i]=pre[i-1]+a[i];
	 	pre[i]%=mod;
	 }
	 long long ans=0;
	 for(int i=n;i>=1;i--){
	 	ans+=a[i]*pre[i-1];
	 	ans%=mod;
	 }
	 cout<<ans<<endl;
} 