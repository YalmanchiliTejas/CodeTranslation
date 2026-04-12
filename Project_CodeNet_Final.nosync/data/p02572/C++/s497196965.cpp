#include<bits/stdc++.h>
using namespace std;
#define vite ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define tst lli T; cin>>T; while(T--)
#define mod 1000000007
#define MAX 1e9
#define MIN -1e9
#define lli long long int
#define vt vector
#define pb push_back
int main()
{
	vite;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	lli n;
	cin>>n;
	lli a[n];
	for(lli i=0;i<n;i++) cin>>a[i];
	lli sum=0,p[n+1]={0};
	for(lli i=n-1;i>=0;i--) p[i]=(p[i+1]+a[i])%mod;
	for(lli i=0;i<n;i++){ sum+=a[i]*p[i+1];sum%=mod;}
	cout<<sum;
	cout<< endl;
	// cout<< fixed << setprecision(6) << 1.0 * clock() / CLOCKS_PER_SEC;
	return 0;
}