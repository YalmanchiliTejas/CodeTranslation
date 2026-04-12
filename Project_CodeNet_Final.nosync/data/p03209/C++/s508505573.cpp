#include <bits/stdc++.h>

#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;

ll solve(ll,ll);
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,x;
    cin>>n>>x;
    cout<<solve(n,x)<<endl;
    return 0;
}

ll solve(ll n,ll x) {
    if(x==0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    ll maki=pow(2,n+1)-3;
    if(x<=1+maki){
        return solve(n-1,x-1);
    }
    else{
        return pow(2,n)+solve(n-1,x-2-maki);
    }
}