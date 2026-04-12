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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
P a[200005];
int ans[200005];
int main(){
	cin>>n;
	rep(i,n){
		cin>>a[i].fi;
		a[i].sc = i;
	}
	sort(a,a+n);
	rep(i,n){
		if(i<n/2){
			ans[a[i].sc] = a[n/2].fi;
		}
		else{
			ans[a[i].sc] = a[n/2-1].fi;
		}
	}
	rep(i,n){
		printf("%d\n",ans[i]);
	}
}