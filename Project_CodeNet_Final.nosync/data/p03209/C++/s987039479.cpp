#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> c(51),p(51);
ll ans=0;

void dfs(ll x,ll n){
    if(n==0) {ans++;return;}
    if(x==1) return;
    else if(x==c[n-1]+2) {ans += 1+p[n-1];return;}
    else if(x==c[n]) {ans+= p[n];return;}
    else if(x<c[n-1]+2) dfs(x-1,n-1);
    else {ans+=1+p[n-1];dfs(x-c[n-1]-2,n-1);}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,x;
    cin >> n >> x;
    c[0] = 1;p[0] = 1;
    for(int i = 1;i <= n;i ++){
        c[i] = 2*c[i-1]+3;
        p[i] = 2*p[i-1]+1;
    }
    dfs(x,n);
    cout << ans << endl;
    return 0;
}