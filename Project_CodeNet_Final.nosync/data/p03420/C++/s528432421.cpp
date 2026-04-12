#include<bits/stdc++.h>
using namespace std;
int n,k;
long long ans;
int main() {
	cin>>n>>k;
	for (int b=k+1;b<=n;++b) {
		ans+=(b-k)*(n/b+1)-min(b-k,b-n%b-1)-!k;
	}
	cout<<ans;
}