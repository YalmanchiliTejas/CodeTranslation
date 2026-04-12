#include<iostream>
#include<vector>
using namespace std;
using ll = long;

ll n, k;

ll fun(ll n, ll x){
	if (n == 0)return (x <= 0 ? 0 : 1);
	ll p = (1LL << n) - 1;
	if (x <= 2*p)return fun(n - 1, x - 1);
	return p + 1 + fun(n - 1, x - 1 - 2*p);
}

int main(){
	cin >> n >> k;
	cout << fun(n, k) << endl;
}
