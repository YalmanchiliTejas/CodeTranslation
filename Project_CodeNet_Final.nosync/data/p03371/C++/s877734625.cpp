#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    unsigned long a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    unsigned long sum1, sum2, ans1, ans2, ans3;
    unsigned long l = min(x, y);
    unsigned long h = max(x, y);

    //lowがcの2パターン
    if(x>y){
    sum1 = l * c * 2 + (h - l) * a;
    ans1 = sum1;
    }
    else if(x<=y){
    sum2 = l * c * 2 + (h - l) * b;
    ans1 = sum2;
    }

    //すべてa,bのパターン
    ans2 = a * x + b * y;

    //すべてcのパターン
    ans3 = c * 2 * h;

    cout << min(ans1, min(ans2, ans3)) << endl;
    return 0;
}