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
typedef pair <int, int> ii;

const int mod = 1e9 + 7;
const ll INF = (1LL<<50);
const double EPSILON = 0.001;
const int N = 1000005;
int main(){
	fastio;
	ll n, x, m;
	map<ll,ll> see;
	cin >> n >> x >> m;
	ll last = x, atual;
	while(true){
		atual = last*last % m;
		last = atual;
		see[atual]++;
		if(see[atual] == 3)break;
	}
	vector<ll> v1, v2;
	ll sum1 = 0, sum2 = 0, aux = 1;
	last = x;
	while(true){
		atual = last*last % m;
		last = atual;
		if(see[atual] == 3 and !aux)break;
		if(see[atual] == 3)aux = 0;
		if(see[atual] == 1)v1.pb(atual), sum1 += atual;
		else v2.pb(atual), sum2 += atual;
	}
	ll ans = x;
	n--;
	if(n < (ll)sz(v1)){
		for(int i = 0; i < n; i++)
			ans += v1[i];
	}else{
		n -= (ll)sz(v1);
		ans += sum1;
		if(n < (ll)sz(v2)){
			for(int i = 0; i < n; i++)
				ans += v2[i];
		}else{
			ans += sum2*(ll)(n/(ll)sz(v2));
			n %= (ll)sz(v2);
			for(int i = 0; i < n; i++)
				ans += v2[i];
		}
	}
	cout << ans << '\n';
	return 0;
}
