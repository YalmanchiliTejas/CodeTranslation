#include<bits/stdc++.h>

using namespace std;
long long a[200005];
long long cnt[200005];
long long ans=0;
const long long MOD=1e9+7;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cnt[1]=a[1];
	for(int i=2;i<=n;i++){
		cnt[i]=(cnt[i-1]+a[i])%MOD;
	}
	for(int i=1;i<=n;i++){
		ans+=a[i]%MOD*(cnt[n]-cnt[i])%MOD;
		ans=ans%MOD;
	}
	cout<<(ans+MOD)%MOD;
	return 0;
}