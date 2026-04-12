#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1000000007

int main() {
	ll a,b,c,A,B,ans=0;
	cin>>a>>b>>c>>A>>B;
	c*=2;
	if(c<=a+b){
		ll D=min(A,B);
		A-=D;B-=D;
		ans+=D*c;
	}
	if(c<=a){
		ans+=A*c;		
		A-=A;
	}
	if(c<=b){
		ans+=B*c;
		B-=B;
	}
	cout << ans+A*a+B*b;
}