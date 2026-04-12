#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mp make_pair
#define fi fisrt
#define se second

using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f;

vector<int> vec[N];

int n,m,k,ans,sum;
int ji;
int a[N];
int num[N];
string s,t;
int lens,lent;
signed main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) sum+=a[i];
	sum%=mod;
	for (int i=1;i<=n;i++) ans+=(a[i]*(sum-a[i])%mod+mod)%mod;
	if (ans%2==1) ans+=mod;
	ans/=2;
	ans%=mod;
	cout<<ans<<endl;
}
