#include <bits/stdc++.h>
using namespace std;


int main(){
    int a, b, c, X, Y, x=0, y=0;
    cin >> a >> b >> c >> X >> Y;
    long long int ans, cost=0;
    ans = a * X + b * Y;
    int i = 1;
    while(x <= X || y <= Y){
        cost = 2 * c * i;
        cost += max(0, X-i) * a + max(0, Y-i) * b;
        ans = min(ans, cost);
        x++;
        y++;
        i++;
    }
    cout << ans << endl;
    return 0;
}