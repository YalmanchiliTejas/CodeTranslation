#include<iostream>
using namespace std;
#define MAXN 200007
#define MO (int(1e9)+7)
int a[MAXN];
inline int qpow(int a, int b) {
	int ans=1;
	for(;b;b>>=1) {
		if(b&1) ans=1ll*ans*a%MO;
		a=1ll*a*a%MO;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for(int i=0; i<n; i++) cin>>a[i];
	int s=0;
	for(int i=0; i<n; i++) {
		s=(s+a[i])%MO;
	}
	s=(long long)s*s%MO;
	for(int i=0; i<n; i++) {
		s=(s-1ll*a[i]*a[i]%MO)%MO;
	}
	s=1ll*s*qpow(2,MO-2)%MO;
	if(s<0) s+=MO;
	cout << s << '\n';
}
