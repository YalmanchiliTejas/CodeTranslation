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

int a[200010];
int b[200010];
int n;

int main()
{
	read(n);
	for(int i=1; i<=n; ++i){
		scanf("%d", a+i); b[i]=a[i];
	}
	sort(b+1, b+n+1);
	for(int i=1; i<=n; ++i) printf("%d\n", b[n/2+(a[i] <= b[n/2])]);
	return 0;
}
