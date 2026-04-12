#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define rep(i,n) for(int i = 0;i < n;i++)
#define NIL = -1;

ll gcd(long long a,long long b) {
    if (a < b) swap(a,b);
    if (b == 0) return a;
    
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    a / gcd(a,b) * b;
}
const ll mod = 1e9 + 7;

int main(){
    int a,b,c,x,y;

    cin >> a >> b >> c >> x >> y;

    int ans = 0;

    if (x < y){
        swap(x,y);
        swap(a,b);
    }

    int d = x - y;
    ans += min(y*(a+b),c*2*y);
    ans += min(d*a,d*c*2);
    cout << ans << endl;
}