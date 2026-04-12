#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    int ab = 0;
    int ans = 1001001000;
    while (!(x == 0 && y == 0)) {
        //printf("%d %d %d : %d\n", x, y, ab, a*x+b*y+c*ab);
        ans = min(ans, a*x + b*y + c*ab);
        x = max(x-1, 0);
        y = max(y-1, 0);
        ab += 2;
    }
    ans = min(ans, c*ab);
    cout << ans << endl;

}
