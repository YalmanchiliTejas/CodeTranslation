#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define cout_precision cout.setf(ios::fixed); cout.precision(32);
#define clr(a) memset(a,0,sizeof(a))
#define umap unordered_map
#define uset unordered_set
#define fr first
#define sc second
#define pb push_back
#define pf push_front
#define M int(1e9+7)
#define endl '\n'
#define largest(a,b,c) (a>b?(a>c? a:c):(b>c? b:c))
#define smallest(a,b,c) (a<b?(a<c? a:c):(b<c? b:c))

using ll = int64_t; using vll = vector<ll>; using vvll = vector<vll>;
using pll = pair<ll, ll>; using vpll = vector<pll>; using vvpll = vector<vpll>;



int main() {
	fast_io; cout_precision;
	int n;	cin >> n;
	ll arr[n];
	for(int i=0; i<n; i++)	cin >> arr[i];
	ll res = 0;
	ll sum = 0;
	for(int i=0; i<n; i++){
		sum += arr[i];
	}
	ll curr = 0;
	for(int i=0; i<n; i++){
		curr += arr[i];
		res = (res%M +((arr[i]%M)*((sum-curr)%M))%M)%M;
	}
	cout << res%M<<endl;

	return 0;
}
