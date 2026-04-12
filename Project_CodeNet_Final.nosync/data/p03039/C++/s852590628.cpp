#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define pb push_back
typedef long long ll;
typedef long double ld;

using namespace std;
#define int long long
const int md = 1e9 + 7;
ll gcdex(ll a, ll mod = md) {
	ll g = mod, r = a, x = 0, y = 1;
	while (r != 0) {
		ll q = g / r;
		g %= r;
		swap(g, r);
		x -= q * y;
		swap(x, y);
	}
	return x < 0 ? x + mod : x;
}
signed main(){
    int n , m , k;
    cin >> n  >> m  >> k;
    k-=2;
    vector < int > fact(n*m+1);
    fact[0]  = 1;
    for(int i = 1; i <= n*m;++i){
        fact[i] = fact[i-1]*i;
        fact[i]%=md;
    }
    int answer = fact[n*m-2]*gcdex((fact[n*m-k-2]*fact[k])%md);
    answer %= md;
    int ans = 0;
    for(int i= 0  ;i  < n; ++i){
        for(int j = 0; j < m ; ++j){
            int now = j*(j+1)/2;
            now *= n , now %= md;
            int second = (m-j-1)*(m-j)/2;
            second *= n , second %= md;
            ans += now + second , ans %= md;

            now = i*(i+1)/2;
            now *= m , now %= md;
            second = (n-i-1)*(n-i)/2;
            second *= m , second %= md;
            ans += now + second , ans %= md;
        }
    }
    ans *= answer;
    ans %= md;
    ans *= gcdex(2);
    ans %= md;
    cout << ans;
    return 0;
}
