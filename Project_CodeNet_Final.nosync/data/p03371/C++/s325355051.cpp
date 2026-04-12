#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    //お得
    if(a+b >= c*2){
        //余りなし
        int ans1 = 0;
        ans1 += min(x, y) * 2 * c;
        if(x > y) ans1 += (x-y) * a;
        else ans1 += (y-x) * b;

        //cのみ
        int ans2 = 0;
        ans2 += 2 * c * max(x, y);

        //統合
        ans = min(ans1, ans2);
    }

    //単品のみ
    else{
        ans += a * x + b * y;
    }

    cout << ans << endl;
    return 0;
}
