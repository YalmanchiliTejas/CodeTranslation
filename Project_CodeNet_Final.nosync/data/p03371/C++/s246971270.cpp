#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = 0;
    if(a + b <= 2 * c){
        ans = a * x + b * y;
    }else{
        if(x > y){
            ans += y * 2 * c;
            if(a <= 2 * c){
                ans += (x - y) * a;
            }else{
                ans += (x - y) * 2 * c;
            }
        }else{
            ans += x * 2 * c;
            if(b <= 2 * c){
                ans += (y - x) * b;
            }else{
                ans += (y - x) * 2 * c;
            }
        }
    }
    cout << ans << endl;
}