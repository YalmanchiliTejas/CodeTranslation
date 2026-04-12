#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, x;
    cin >> n >> x;
    vector<ll> p(n + 1, 1LL), b(n + 1, 1LL);
    for(int i = 1; i <= n; i++){
        p[i] = p[i-1] + 1 + p[i-1];
        b[i] = 1 + b[i-1] + 1 + b[i-1] + 1;
    }
    ll sum = 0LL;
    for(int i = n; i >= 1; i--){
        if(x == 0) break;
        x--;
        if(x <= b[i-1]) continue;
        sum += p[i-1] + 1;
        x -= b[i-1] + 1;
    }
    if(x) sum++;
    cout << sum << endl;
    return 0;
}
