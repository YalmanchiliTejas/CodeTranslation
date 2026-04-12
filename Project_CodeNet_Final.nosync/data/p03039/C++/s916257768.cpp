#include <bits/stdc++.h>
#define mm(x,k) memset (x, k, sizeof(x));
#define ll long long
#define ff(i,a,b) for(ll i = a ; i  < b ; ++i)
#define fd(i,a,b) for(ll i = a ; i <= b ; ++i)
using namespace std;
#define mo 1000000007
ll mod(ll a , ll b){
    ll t = 1;
    while(b){
        if(b&1) t = a * t % mo;
        b >>= 1; a = a * a % mo;
    } return t;
}
ll a[200005];
ll C(ll n , ll m){
    return (a[n] * mod(a[n-m],mo-2)) % mo * mod(a[m],mo-2) %mo;
}
int main(){
    a[0] = 1;
    ff(i,1,200005) a[i] = a[i-1] * i % mo;
    ll n , m , k;
    cin >> n >> m >> k;
    cout<< C(n*m,k)*C(k,2)%mo*(n+m)%mo*mod(3,mo-2)%mo;
}