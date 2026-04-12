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
int n,k;
int main(){
	cin>>n>>k;
	ll ans = 0;
	for(int r=k+1;r<=n;r++){
		for(ll d=0;;d++){
		    if(d*r+k > n) break;
		    //d*r+k ~ d*r+r-1
		    ans += min(d*r+r-1,1LL*n)-max(d*r+k,1LL)+1;
		}
	}
	cout<<ans<<endl;
}
