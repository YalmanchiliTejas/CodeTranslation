#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
const double eps = 1e-8;
const int NINF = 0xc0c0c0c0;
const int INF  = 0x3f3f3f3f;
const ll  mod  = 998244353;
const ll  maxn = 1e6 + 5;
const int N = 3050;

ll n,s,a[N],f[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll res=0;
	for(int i=1;i<=n;i++){
		f[0]++;
		for(int j=s;j>=a[i];j--){
			f[j]=(f[j]+f[j-a[i]])%mod;
		}
		res=(res+f[s])%mod;
	}
	cout<<res<<'\n';
	return 0;
}