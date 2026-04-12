#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define pb push_back
#define endl '\n'
#define snd second
#define fst first
#define fastio cin.tie(NULL),cout.sync_with_stdio(true)

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef pair <ii,int> iii;

const int mod = 1e9 + 7;
const ll INF = (1LL<<50);
const int N = 300005;

ll sum[N], v[N];

void add_self(ll &a, ll b){
	a += b;
	if(a >= mod)
		a-=mod;
}

ll mul(ll a, ll b){
	return 1ll* a * b % mod;
}

ll sub(ll a, ll b){
	return (a-b+mod)%mod;
}

int main(){
	fastio;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> v[i];
	sum[0] = v[0];
	for(int i = 1; i < n; i++){
		add_self(sum[i], v[i]);
		add_self(sum[i], sum[i-1]);
	}
	ll ans = 0;
	for(int i = 0; i < n-1; i++){
		add_self(ans, mul(v[i], sub(sum[n-1],sum[i])));
	}
	cout << ans << '\n';
	return 0;
}
