#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001
#define fi first
#define se second

vll a(51,-1);
vll p(51,-1);
ll func(ll x,int l){
	if(x==0) return 0;
	if(l==0) return 1;
	if(x<(a[l]+1)/2) return func(x-1,l-1);
	else return p[l-1]+1+func(min(x-2-a[l-1],a[l-1]),l-1);
}

int main(void) {
	int n; cin >> n;
	ll x; cin >> x;
	a[0] = 1;
	p[0] = 1;
	rep(i,n) a[i+1] = a[i]*2+3;
	rep(i,n) p[i+1] = p[i]*2+1;
	cout << func(x,n) << endl;
}
