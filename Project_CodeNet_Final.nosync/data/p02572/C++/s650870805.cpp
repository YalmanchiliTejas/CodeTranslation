#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

const int MOD=1000000007;

int main(){
	int n;cin>>n;
	ll A=0,B=0;
	rep(i,n){
		ll a;scanf("%lld",&a);
		(A+=a)%=MOD;
		(B+=a*a)%=MOD;
	}
	ll t=(MOD+1)/2;
	cout<<(A*A%MOD+MOD-B)%MOD*t%MOD<<endl;
}