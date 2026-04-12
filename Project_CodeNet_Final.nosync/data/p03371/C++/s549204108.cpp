#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    if(a+b<=2*c){
        cout << a * x + b * y << endl;
    }
    else{
        if(x<y){
            ll tmp = 0;
            tmp = y - x;
            cout << min(x * 2 * c + tmp * b, 2 * c * y) << endl;
        }
        else{
            ll tmp = 0;
            tmp = x - y;
            cout << min(2* x * c, y * 2 * c + tmp * a) << endl;
        }
    }
    return 0;
}
