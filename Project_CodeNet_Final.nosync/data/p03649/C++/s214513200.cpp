#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

int n;
ll a[51];

bool Check_single(ll t){
	ll need = 0;
	for(int i=1; i<=n; ++i){
		ll p = a[i];
		p += t;
		p -= (n-1);
		if(p <= 0) continue;
		need += (p + n) / (n+1);
	}
	return need <= t;
}

bool Check(ll t){
	for(int i=0; i<n; ++i) if(Check_single(t+i)) return 1;
	return 0;
}

int main()
{
	cin >> n;
	for(int i=1; i<=n; ++i) cin >> a[i];
	ll l=-1, r=ll(1e18);
	while(l+1<r){
		ll mid=(l+r)/2;
		(Check(mid)?r:l)=mid;
	}
	for(int i=0; i<n; ++i) if(Check_single(r+i)){
		cout << r+i << endl;
		break;
	}
	return 0;
}
