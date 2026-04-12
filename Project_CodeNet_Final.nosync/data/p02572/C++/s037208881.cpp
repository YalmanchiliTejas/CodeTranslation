#include<bits/stdc++.h>
using namespace std;
int main(){
	const int P=1e9+7;
	const int inv2=P-P/2;
	int n;
	cin>>n;
	int sum=0,sq=0;
	int ans=0;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		ans=(ans+1ll*sum*a)%P;
		sum=(sum+a)%P;
	}
	cout<<ans;
}