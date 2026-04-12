#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    int x, y;
    cin >> a >> b >> c  >> x >> y;
    int res= 10000000;
    // a,b ばら買い
    int p1 = a*x + b*y;
    // 全部セットで買うとき
    int p2 = 2 * c * max(x, y);
    // 必要最小限のcを買って、その他をabで埋める
    int tmp = x < y ? b : a;
    int p3 = 2 * c * min(x, y) + tmp*abs(x-y);
    res = min(p1, min(p2, p3));
    cout << res << endl;
    return 0;
}