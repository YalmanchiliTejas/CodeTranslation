#include <iostream>
using namespace std;
typedef long long ll;
ll p[55];
ll f(ll n, ll x){
    if(n == 0) return 1;
    if(x == 1) return 0;
    if(x == p[n+2] - 3) return p[n+1] - 1;
    ll res = 0;
    if(x == p[n+1] - 1){
        return p[n];
    }
    if(x > p[n+1] - 1){
        res += p[n];
        x -= p[n+1] - 1;
    }else x--;
    
    return res + f(n-1, x);
}
int main() {
    ll n, x;
    cin >> n >> x;
    p[0] = 1;
    for(int i=1;i<55;i++) p[i] = p[i-1] * 2;
    cout << f(n, x) << endl;
	return 0;
}