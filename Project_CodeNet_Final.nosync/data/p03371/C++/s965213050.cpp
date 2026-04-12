#include <bits/stdc++.h>
#define rep(i,n) for(long long int i = 0; i < n; i++)
#define _rep(i,m,n) for(long long int i = m; i < n; i++)
#define print(n) std::cout << n << std::endl
#define _print(n) std::cout << n
using namespace std;
typedef long long ll;
const int N = 1000000;
const ll mod = 1000000007;
int digits(ll m){
    int count = 0;
    while (m > 0){
        m /= 10;
        count++;
    }
    return count;
}
int main() {
    int a,b,c,x,y; cin >> a >> b >> c >> x >> y;
    int z = 2 * max(x,y);
    ll sum = 0;
    ll sum_min = INFINITY;
    for (int i = 0; i <= z; i += 2) {
        if((x - i/2 >= 0) && (y - i/2 >= 0)) {
            sum = c * i + a * (x - (i / 2)) + b * (y - (i / 2));
        }
        if(x - i/2 < 0)sum = c * i + b * (y - (i / 2));
        if(y - i/2 < 0)sum = c * i + a * (x - (i / 2));
        sum_min = min(sum,sum_min);
    }
    print(sum_min);
}
