#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >>x >> y;
    
    long long ans = LONG_MAX;
    for (int ab = 0; ab <= max(x, y); ab++){
        int numA = max(x - ab, 0);
        int numB = max(y - ab , 0);
        ans = min(ans, (long long)2 * ab * c + numA * a + numB * b);
    }
    cout << ans << endl;
}