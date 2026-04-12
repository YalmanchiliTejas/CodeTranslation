#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
#include<map>
#include<queue>

using namespace std;

#define INF 2000000000;

int main(void){

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = INF;

    for(int i = 0;i <= max(x, y);i++){
        ans = min(ans, i * 2 * c + max(0, x - i) * a + max(0, y - i) * b);
    }

    cout << ans << endl;
    return 0;
}