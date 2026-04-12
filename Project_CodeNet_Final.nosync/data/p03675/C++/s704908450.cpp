//15:53-17:33
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
int main(){
	deque<int>a;
	int n; cin >> n;
	rep(i,n){
		int x; cin >> x;
		if((n-1-i)%2 == 0) a.push_front(x);
		else a.push_back(x);
	}
	rep(i,n) cout << a[i] << (i==n-1?'\n':' ') ;
}