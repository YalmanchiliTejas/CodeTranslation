#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug(x) cout<<x<<endl
#define int long long 
const int mod=1000000007;
int powmod(int a,int b) {int res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int gcd(int a,int b) { return b?gcd(b,a%b):a;}
inline int read() {int num=0, w=0;char ch=0;while (!isdigit(ch)) {w|=ch=='-';ch = getchar();}while (isdigit(ch)) {num = (num<<3) + (num<<1) + (ch^48);ch = getchar();}return w? -num: num;}
// cin.tie(0);
// ios::sync_with_stdio(false);
// head
// long long *long long 		**
//all 
signed main()
{
	int n;
	n=read();
	if(n>=30){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
    return 0;
}