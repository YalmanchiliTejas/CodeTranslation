#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    ll n,x,m;
    cin >> n >> x >> m;
    vector<bool> check(m+1,false);
    vector<ll> a;
    ll rs;
    check[x] = true;
    a.push_back(x);

    while(1){
        ll f = (x*x) %m;
        if(check[f] == true){
            rep(i,a.size()){
                if(a[i] == f)rs = i;
            } 
            break;
        }
        else{
            check[f] = true;
        }
        x = f;
        a.push_back(x);

    }
    ll roop = a.size() - rs;
    ll ans = 0;
    vector<ll>asum(a.size());

    rep(i,a.size()){
        if(i == 0)asum[i] = a[i];
        else asum[i] = asum[i-1]+a[i];
    }

    if(n < rs ){
        ans = asum[n];
    }
    else {
        ans = asum[rs] - a[rs];
        n = n-rs;
        ans += (n/roop)*(asum[asum.size()-1]-(asum[rs]-a[rs])) + ((asum[n%roop+rs]-a[n%roop+rs]) -(asum[rs]-a[rs]));
    }

    cout << ans << endl; 

    return 0;
}