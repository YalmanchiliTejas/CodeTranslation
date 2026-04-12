#include<bits/stdc++.h>
using namespace std;

int n;
long long a[200002];
long long b[200002];
long long sum = 0;
long long ans = 0;
int main(){

	cin>>n;
	a[0] = b[0] = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	for(int i=n;i>0;i--){
		sum += a[i];
		sum %= 1000000007ll;
		ans += sum*a[i-1];
		ans %= 1000000007ll;
	}

	cout<<ans<<endl;

	return(0);
}