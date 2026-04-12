#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int x, y;
    cin >> x >> y;
    if (x < y) {
        swap(x, y);
        swap(a, b);
    }
    int ans = 0;
    if (a + b >= c * 2) {
        ans += y * c * 2;
        x -= y;
        if (x > 0) {
            if (a >= c * 2) {
                ans += x * c * 2;
            } else {
                ans += x * a;
            }
        }
    } else {
        ans += x * a + y * b;
    }
    cout << ans << endl;
        
    return 0;
}
