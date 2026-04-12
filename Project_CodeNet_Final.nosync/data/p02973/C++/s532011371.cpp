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
int n,a[100005];
int val[100005];
int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	val[0] = -1;
	for(int i=1;i<100005;i++) val[i] = INF+4;
	for(int i=n-1;i>=0;i--){
		int b = upper_bound(val,val+100005,a[i])-val;
		val[b] = a[i];
	}
	for(int i=100001;i>=0;i--){
		if(val[i] != INF+4) {cout<<i<<endl;return 0;}}
}
