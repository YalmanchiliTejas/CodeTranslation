#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i,a,n) for (int i=a; i<n; i++)

int a[200005];
int num[200005];
const int INF=1000000007;

signed main(){
	ios::sync_with_stdio(false);
   	cin.tie(0);

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int n;
	cin>>n;
	int sum=0;
	forn(i,0,n){
		cin>>a[i];
		sum+=a[i];
	}
	num[0]=sum-a[0];
	forn(i,1,n)
		num[i]=num[i-1]-a[i];
	int ans=0;
	forn(i,0,n){
		num[i]%=INF;
		ans+=a[i]*num[i];
		ans%=INF;
	}
	cout<<ans<<endl;
	return 0;
}