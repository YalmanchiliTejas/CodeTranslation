#include<bits/stdc++.h>

#define LL long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL lcm(LL a,LL b){return a/gcd(a,b)*b;}
LL powmod(LL a,LL b,LL MOD){LL ans=1;while(b){if(b%2)ans=ans*a%MOD;a=a*a%MOD;b/=2;}return ans;}
const int N = 2e5 +11;
int main(){
	ios::sync_with_stdio(false);
	int n,a[3333];
	cin>>n;
	int ans=0,pre;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(i==1)ans++,pre=a[1];
		else if(a[i]>=pre)ans++,pre=a[i];
	}
	cout<<ans;
	return 0;
}