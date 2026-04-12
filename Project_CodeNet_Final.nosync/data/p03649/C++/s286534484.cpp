#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n; ll a[55];
int main(){
	cin>>n;
	rep(i,n) cin>>a[i];
	sort(a,a+n);
	ll ret = 0LL;
	for(int i=n-1;i>=0&&a[n-1];i--){
		//[i,n-1]
		ll prev = (i==0?0LL:a[i-1]);
		ll dif = a[i]-prev;
		ll num = dif/(n*1LL+1LL);
		ret += num*1LL*(n-i); //cout << ret << endl;
		for(int j=0;j<i;j++) a[j]+=num*(n-i);
		for(int j=i;j<n;j++) a[j]+=(-1-i)*1LL*num;
		rep(q,n){
			if(a[n-1]<n)break;
			a[n-1]-=n;
			for(int i=0;i<n-1;i++) a[i]++;
			ret++;
			sort(a,a+n);
		}
	}
	ll add = 5e18;
	for(int i=0;i<n;i++){
		add = min(add,max(0LL,a[n-1]-n*1LL+1LL)*n+1LL*i);
		a[n-1]-=n;
		for(int i=0;i<n-1;i++) a[i]++;
		sort(a,a+n);
	}
	cout << ret+add << endl;
}