#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int a, b, c, x, y, ans;

    cin >> a >> b >> c >> x >> y;

    ans = __INT_MAX__;

    for(int i = 0 ; i <= 100000; i++){
        ans = min(ans, 2*i*c + max(0, x-i)*a + max(0, y-i)*b);
    }

    cout << ans << endl;

    return 0;
}
