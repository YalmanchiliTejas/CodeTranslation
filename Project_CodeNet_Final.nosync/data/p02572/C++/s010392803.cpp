#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
ll a[N],suf[N];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	for(int i=n;i>=1;i--) 
		suf[i]=(suf[i+1]+a[i])%mod;
	ll s=0;
	for(int i=1;i<n;i++)
		s=(s+a[i]*suf[i+1])%mod;
	cout<<s<<endl;
 	return 0;
}