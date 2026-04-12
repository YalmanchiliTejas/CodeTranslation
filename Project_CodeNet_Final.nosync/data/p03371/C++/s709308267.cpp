#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
//typedef ll int;
ll mod = 1000000007;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, c;
    ll ans = -1, first = 0, second = 0;
    ll x, y;
    cin >> a >> b >> c >> x >> y;
    if(2*c <= a && 2*c <= b) first = max(x, y) * 2 * c;
    else if(2*c <= a){
        first += (2*c*x);
        first += max(y-x, 0LL) * b;
    }
    else if(2 * c <= b){
        first += (2 * c * y);
        first += max(x-y, 0LL) * a;
    }
    else if(a + b >= 2*c){
        if(x > y){
            first += 2 * c * y;
            first += (x-y)*a;
        }
        else first += 2*c*x + (y-x) * b;
    }
    else first = (a*x + b *y);
    cout << first << endl;
}