#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
const int m=1e9+7;

int main(){
	int n; cin>>n;
	vector<int> v(n);
	rep(i,n) cin>>v[i];
	
	vector<ll> b(n+1,0);
	rep(i,n) b[i+1]=b[i]+v[i];
	
	ll sum=0, ans=0;
	rep(i,n){
		sum=(b[n]-b[i+1])%m;
		ans+=v[i]*sum;
		ans%=m;
	}
	cout<<ans%m<<endl;
}