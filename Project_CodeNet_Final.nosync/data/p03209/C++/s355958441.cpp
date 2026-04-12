#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
ll solve(ll n, ll x){
	if(x<=n || n<0) return 0;
	if(x<=(ll)pow(2,n+1)-2) return solve(n - 1,x - 1);
	else return solve(n - 1,x - (ll)pow(2,n+1) + 1) + (ll)pow(2,n);
}

int main(){
	ll n,x;
	cin >> n >> x;
	cout << solve(n,x) << endl;
}