#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> a, p;

ll f(ll n, ll x){
    if(n==0) return 1;

    if(x==1) return 0;
    else if(x<=1+a[n-1]) return f(n-1,x-1);
    else if(x==2+a[n-1]) return p[n-1]+1;
    else if(x<=2+2*a[n-1]) return p[n-1]+1+f(n-1, x-2-a[n-1]);
    else return 2*p[n-1]+1;
}

int main(void){
    ll n, x; cin >> n >> x;
    a.push_back(1); p.push_back(1);
    for(int i=0; i<n; i++){
        a.push_back(2*a[i]+3);
        p.push_back(2*p[i]+1);
    }

    cout << f(n,x) << endl;
}