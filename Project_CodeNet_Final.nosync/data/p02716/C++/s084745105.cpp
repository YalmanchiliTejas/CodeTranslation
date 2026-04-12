#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const double eps = 1e-8;
const int NINF = 0xc0c0c0c0;
const int INF  = 0x3f3f3f3f;
const ll  mod  = 1e9 + 7;
const ll  maxn = 1e6 + 5;
const int N = 2e5 + 5;

ll n,a[N],f[N],sum[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(i>1?sum[i-2]:0)+a[i];
	}
	for(int i=2;i<=n;i++){
		if(i&1) f[i]=max(f[i-2]+a[i],f[i-1]);
		else f[i]=max(f[i-2]+a[i],sum[i-1]);
	}
	cout<<f[n]<<'\n';
	return 0;
}