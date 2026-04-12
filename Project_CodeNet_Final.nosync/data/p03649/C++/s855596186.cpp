#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=1;i<=n;i++)
#define ld long double
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
int n;
ll a[100],k=0;
ll lim;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	lim=n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	while (a[n]>=n){
		ll t=a[n]/n;
		k+=t;
		a[n]%=n;
		rep(i,n-1) a[i]+=t;
		sort(a+1,a+n+1);
	}
	cout<<k;
}