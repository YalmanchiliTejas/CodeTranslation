#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int main()
{
    int a, b, c, x, y;
    int mini, dis, ans;
    
    cin >> a >> b >> c >> x >> y;
    
    mini = min(x, y);
    dis = max(x, y) - mini;
    
    if((a + b) < 2 * c) {
        ans = (a + b) * mini;
    } else {
        ans = mini * 2 * c;
    }
    
    if(x > y) {
        if(a > 2 * c) { ans += 2 * c * dis; }
        else { ans += a * dis; }
    } else if(x < y) {
        if(b > 2 * c) { ans += 2 * c * dis; }
        else { ans += b * dis; }
    }
    
    cout << ans << endl;
    
    return 0;
}
