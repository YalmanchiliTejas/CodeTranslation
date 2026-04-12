#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll a[60];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(sort(a+1,a+n+1);a[n]>=n;sort(a+1,a+n+1)){for(int i=0;i<n;++i)a[i]+=a[n]/n;a[n]%=n;}
	cout<<a[0]<<'\n';
	return 0;
}
