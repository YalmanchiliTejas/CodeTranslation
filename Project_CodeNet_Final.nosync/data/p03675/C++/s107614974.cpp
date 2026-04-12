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

int main()
{
	deque<int> dq;
	int n;
	read(n);
	for(int i=1; i<=n; ++i){
		int a; read(a);
		if(i%2 == 1) dq.pb(a);
		else dq.push_front(a);
	}
	if(n&1) reverse(all(dq));
	for(int x:dq) printf("%d ", x);
	return 0;
}
