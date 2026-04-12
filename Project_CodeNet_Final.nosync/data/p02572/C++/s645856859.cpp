#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
const int MOD=1e9+7;
int ans;
int n,a[200005],sum[200005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sum[n-1]=a[n-1];
	for(int i=n-2;i>0;i--) sum[i]=(a[i]+sum[i+1])%MOD; 
	//for(int i=1;i<n;i++) cout<<i<<':'<<sum[i]<<"\n";
	for(int i=0;i+1<n;i++){
		int cur=a[i]*sum[i+1]%MOD;
		ans=(ans+cur)%MOD;
	}
	cout<<ans;
	re 0;
}