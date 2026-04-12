#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
vector<ll> a , p;
ll f(ll n , ll x){
	if(n == 0){
        return ((x <= 0) ? 0 : 1);
    }
	else if(x <= 1 + a[n - 1]){
        return f(n - 1 , x - 1);
    }
	else{
        return p[n - 1] + 1 + f(n - 1 , x - 2 - a[n - 1]);
    }
}
int main(){
	ll n , x;
	cin >> n >> x;
	a.push_back(1);
	p.push_back(1);
	for(int i = 0; i < n; i++){
		a.push_back(a[i] * 2 + 3);
		p.push_back(p[i] * 2 + 1);
	}
	cout << f(n , x) << endl;
	return 0;
}