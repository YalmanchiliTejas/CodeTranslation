#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define f(i,n) for(int i=0; i<n; ++i)
#define fi(i,st,n) for(int i=st; i<=n; ++i)
#define veci vector<int>
#define vecp vector<pair<int,int> >
#define vecl vector<ll>
int prime[100000+10];

ll lcm(ll a, ll b) {
	return a*b/__gcd(a,b);
}

ll power(ll a, ll n, ll mod) {
	ll res = 1;
	while(n > 0) {
		if(n&1) {
			res = (res*a)%mod;
		}
		a = (a*a)%mod;
		n = n/2;
	}
	return res;
}

ll sum(int arr[], int n) {
	ll res = 0;
	f(i,n) {
		res += arr[i];
	}
	return res;
}

void seive() {
	prime[1] = 0;
	for(int i=2; i<=100000; i++) {
		prime[i] = 1;
	}
	for(ll i=2; i<=100000; i++) {
		if(prime[i]) {
			for(ll j=i*i; j<=100000; j+=i) {
				prime[j] = 0;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,x,m;
	cin>>n>>x>>m;
	set<ll> st;
	vector<ll> v;
	st.insert(x);
	v.pb(x);
	ll ans = 0;
	for(ll i=1; i<=n; i++) {
		ans += x%m;
		x = x*x%m;
		if(st.find(x) != st.end()) {
			ll sum = 0;
			int pos = 0;
			for(; pos<v.size(); pos++) {
				if(v[pos] == x) {
					break;
				}
			}
			for(int i=pos; i<v.size(); i++) {
				sum += v[i];
			}
			ans += ((n-i)/(v.size()-pos))*sum;
			ll rem = (n-i)%(v.size()-pos);
			
			while(rem) {
				ans += v[pos];
				pos++;
				rem--;
				if(pos == v.size()) {
					pos = 0;
				}
			}
			break;
		}
		st.insert(x);
		v.pb(x);
	}
	cout<<ans<<"\n";
 	return 0;
}
