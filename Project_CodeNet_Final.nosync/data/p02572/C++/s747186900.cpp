//177 c 求乘积之和
#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+6;
long long sl[MAX],sz[MAX];
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>sl[i];
		sz[i]=(sz[i-1]+sl[i]); 
	}
	long long ans=0;
	for (int j=1;j<=n;j++) {
		ans+=(sl[j]%1000000007)*((sz[n]-sz[j])%1000000007);
		ans%=1000000007;
	}
	cout<<ans<<endl;
	return 0;
} 