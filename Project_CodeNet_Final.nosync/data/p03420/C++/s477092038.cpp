#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,ans;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	if (k==0){
		cout<<n*n;
		return 0;
	}
	for (int b=k+1;b<=n;b++){
		ans+=(b-k)*(n/b);
		for (int m=k;m<=n%b;m++) ans++;
	}
	cout<<ans;
	return 0;
}