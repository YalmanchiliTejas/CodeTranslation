#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll s[51],p[51];
ll f(ll N,ll X){
	if(N==0&&X==1)return 1;
	else if(X==1)return 0;
	if(1<X&&X<=1+s[N-1])return f(N-1,X-1);
	else if(X==2+s[N-1])return p[N-1]+1;
	else if(2+s[N-1]<X && X<=2+2*s[N-1]) return p[N-1]+1+f(N-1,X-2-s[N-1]);
	else if(X==3+2*s[N-1])return 2*p[N-1]+1;
}
int main(void){
	ll N,X;
	cin >> N >> X;
	ll ans = 0;
	s[0] = 1;
	p[0] = 1;
	for(int i=1;i<=N;i++){
		s[i] = 2*s[i-1]+3;
		p[i] = 2*p[i-1]+1;
	}
	ans = f(N,X);
	cout << ans << endl;
}	