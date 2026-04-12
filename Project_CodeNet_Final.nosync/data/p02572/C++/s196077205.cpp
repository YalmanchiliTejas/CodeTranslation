#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int main(){
	int n,a;
	__int128 s=0,ss=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		s+=a;
		ss+=a*1LL*a;
	}
	cout<<(int)(((s*s-ss)/2LL)%mod)<<endl;
}