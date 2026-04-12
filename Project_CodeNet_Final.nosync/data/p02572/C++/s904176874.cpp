#include<bits/stdc++.h>
using namespace std;
const int maxn=200009;
const int P=1000000007;

int n;
int a[maxn];
long long sum[maxn];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		sum[i]=(sum[i-1]+a[i])%P;
	}
	long long ans=0;
	for(int i=2;i<=n;++i){
		ans=(ans+a[i]*sum[i-1])%P;
	}
	cout<<ans<<endl;
	return 0;
}