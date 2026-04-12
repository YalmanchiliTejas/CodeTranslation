#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007
ll exp(ll taban, ll us) {
    ll carpan = taban % mod;
    ll temp = us;
    ll res = 1;
    while(temp){
        if(temp % 2) res = (res*carpan) % mod;
        temp /= 2;
        carpan = (carpan*carpan) % mod;
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
double fonk(double x, double y){
	return x*x + y*y;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	bool x = false, y = false;
    for(int i = 0; i < 3; i++){
		char c; cin>>c;
		if(c == 'A') x = true;
		else y = true;
	}
	x&&y ? cout<<"Yes" : cout<<"No";
}