#include <bits/stdc++.h>

#define x first
#define y second

#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cerr << #x << ": " << x << endl;
#endif

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

const int mod=1000000000+7;

int addm(int& a,int b) {return (a+=b)<mod?a:a-=mod;}

template<class T,class U> bool smin(T& a,U b) {return a>b?(a=b,1):0;}
template<class T,class U> bool smax(T& a,U b) {return a<b?(a=b,1):0;}

ll ct[50];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0;i<n;i++) cin >> ct[i];
	ll ans=0;

	bool did=0;
	for (int i=0;i<n;i++) {
		ll td=ct[i]/n;
		if (td) {
			did=1;
			ct[i]%=n;
			for (int j=0;j<n;j++) if (i!=j) ct[j]+=td;
			ans+=td;
		}
		if (i+1==n && did) i=-1,did=0;
	}

	cout << ans << endl;
}