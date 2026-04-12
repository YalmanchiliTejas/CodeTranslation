#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
const int mod = 1e9+7;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
char s[N];
int n,m,mx;
int f[N],f2[N],ans;

int main()
{
	cin >> n >> m;
	scanf("%s",s+1);
	int p;
	for(p=1;p<=m;p++){
		if(s[p]!=s[1])break;
	}
	mx=p-1;
	if(mx==m){
		f[0] = f2[0] = ans = 1;
		for(int i=0;i<=n;i++){
			if(i>=2)f[i] = f2[i-2];
			f2[i] = add((i-1>=0?f2[i-1]:0),f[i]);
			if(n-i>=2)ans = add(ans, 1ll*f[i]*(n-i)%mod);
		}
		cout << ans << endl;
		return 0;
	}
	if(n&1){
		puts("0");
		return 0;
	}
	if(mx%2==0)++mx;
	for(int t=0;p<=m;p++){
		if(s[p]==s[1])++t;
		else{
			if(t&1)mx = min(mx, t);
			t=0;
		}
	}
	n/=2,mx=(mx+1)/2;
	f[0]=f2[0]=1;
	for(int i=0;i<=n;i++)
	{
		if(i)
		{
			f[i]=(mod+f2[i-1]-(i-mx-1>=0?f2[i-mx-1]:0))%mod;
			f2[i]=(f2[i-1]+f[i])%mod;
		}
		if(n-i<=mx) ans = add(ans,(mod+1ll*(n-i)*f[i]*2%mod)%mod);
	}
	cout<<ans;
}