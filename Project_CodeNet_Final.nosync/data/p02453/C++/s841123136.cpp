#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(ll I = ll(A); I < ll(B); ++I)
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
 
int main(){
	ll n,q,k;
	cin >> n;
	vector<ll> a(n);
	FOR(i,0,n){
		cin >> a[i];
	}
	cin >> q;
	FOR(i,0,q){
		cin >> k;
		cout << POSL(a,k) << endl;
	}
}
