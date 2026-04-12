#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)

ll num(ll n){
    return pow(2,n+2)-3;
}

ll solve(ll n,ll x){
    if(n==0) return 1;
    if(x==1) return 0;
    if(x<=num(n-1)+1) return solve(n-1,x-1);
    if(x==num(n-1)+2) return solve(n-1,num(n-1))+1;
    if(x==num(n)) return 2*solve(n-1, num(n-1))+1;
    return solve(n-1,num(n-1))+solve(n-1,x-num(n-1)-2)+1;
}

int main() {
    ll n,x;
    cin >> n >> x;
    cout << solve(n,x) << endl;
}