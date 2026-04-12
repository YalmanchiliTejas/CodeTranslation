#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <string>
#include <math.h>
#include <iomanip>
#include <cassert>
#include <random>
using namespace std;

#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define pb push_back
#define FOR(i, n) for(int i = 0; i < (n); i++)
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

const int mod = 1e9 + 7;
const int mod2 = 998244353;

void fact_init(int n);
ll exp(ll taban, ll us, ll md);
ll ebob(ll a, ll b);
ll ekok(ll a, ll b);
ll komb(ll a, ll b);

vector<ll> fact;
vector<ll> inv_fact;
void fact_init(int n){
    fact.resize(n+5);
    inv_fact.resize(n+5);
    fact[0] = inv_fact[0] = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = (fact[i-1] * i) % mod;
        inv_fact[i] = exp(fact[i], mod-2, mod);
    }
}
ll exp(ll taban, ll us, ll md) {
    ll carpan = taban % md;
    if(carpan == 0) return 0;
    ll temp = us;
    ll res = 1;
    while(temp){
        if(temp % 2) res = (res*carpan) % md;
        temp /= 2;
        carpan = (carpan*carpan) % md;
    }
    return res;
}
 
ll ebob(ll a, ll b){
    if(!a)return b;
    return ebob(b%a, a);
}

ll ekok(ll a, ll b){
    return (a*b)/ebob(a, b);
}

ll komb(ll a, ll b){
    if(a < b) return 0;
    return fact[a] * (inv_fact[a-b] * inv_fact[b] % mod) % mod;
}
const int N = 1e6 + 5;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
	ll n, x, m; cin>>n>>x>>m;
	int seen[m] = {};
	ll res = x;
	seen[x] = 0;
	vector<int> vec(1, x);
	int ptr = 0;
	for(int i = 1; !seen[x*x%m]; i++){
		x = x*x%m;
		seen[x] = i;
		vec.pb(x);
	}
	if(n < vec.size()){
		ll sum = 0;
		for(int i = 0; i < n; i++) sum += vec[i];
		cout<<sum<<"\n";
		return 0;
	}
	int start = seen[x*x%m];
	int end = vec.size();
	n -= start;
	end--;
	int kalan = n % (end - start + 1);
	ll carp = n / (end - start + 1);
	ll sum = 0;
	for(int i = 0; i < start; i++) sum += vec[i];
	ll loop = 0;
	for(int i = start; i <= end; i++) loop += vec[i];
	loop *= max(1ll, carp);
	for(int i = start; i < start + kalan; i++) sum += vec[i];
	cout<<sum + loop<<"\n";
}