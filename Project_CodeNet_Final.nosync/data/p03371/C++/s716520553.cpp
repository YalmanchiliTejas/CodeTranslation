#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main(void)
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = 1e9;

    for(int i = 0; i <= 2*max(x, y); i += 2)
    {
        int j = i/2;
        int sum = c*i;
        if(x - j > 0) sum += (x - j)*a;
        if(y - j > 0) sum += (y - j)*b;
        ans = min(ans, sum);
    }

    cout << ans << endl;
    return 0;
}