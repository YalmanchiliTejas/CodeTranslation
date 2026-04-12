#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

vector<ll>lay;
ll n, k;

ll fun(ll n, ll x){
	if (n == 0)return (x <= 0 ? 0 : 1);
	ll p = (1LL << n) - 1;
	if (x <= 2*p)return fun(n - 1, x - 1);
	return p + 1 + fun(n - 1, x - 2 - lay[n - 1]);
}

int main(){
	cin >> n >> k;
	lay.push_back(1);
	for (int i = 1; i <= n; i++){
		ll l = lay[i - 1] * 2 + 3;
		lay.push_back(l);
	}
	cout << fun(n, k) << endl;
}
