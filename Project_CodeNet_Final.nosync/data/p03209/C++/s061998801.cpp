#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;

ll levelN(ll n, ll x) {
    if(x == 0)
        return 0;
    if(n == 0)
        return x;
    ll size = 1;
    ll patty = 1;
    for(size_t i = 0; i < n; i++) {
        size = 2 * size + 3;
        patty = 2 * patty + 1;
    }
    ll mid = (size+ll(1))/ll(2);
    if(x < mid)
        return levelN(n-1, x-1);
    else if(x == mid)
        return levelN(n-1, x-2) + 1;
    else if(x >= size-1)
        return patty;
    else
        return (patty-1)/2 + 1 + levelN(n-1, x-mid);
}

int main(){
    ll N, X;
    cin >> N >> X;
    cout << levelN(N, X) << endl;
    return 0;
}