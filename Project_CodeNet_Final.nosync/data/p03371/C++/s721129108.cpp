#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MOD 1000000007
#define PI 3.141592653589793

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    c *= 2;
    int ans = 1e9;
    for(int i = 0; i <= max(x, y); i++){
        int tmp = max(x-i,0)*a + max(y-i,0)*b + i*c;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
