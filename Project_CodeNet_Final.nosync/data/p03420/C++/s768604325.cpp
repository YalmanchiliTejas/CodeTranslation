#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;cin>>n>>k;
	long long ans=0;
	for(int i=k+1;i<=n;i++)ans+=(long long)(n/i)*(i-k)+std::max(n%i-k+1,0)-!k;
	cout<<ans;
}
