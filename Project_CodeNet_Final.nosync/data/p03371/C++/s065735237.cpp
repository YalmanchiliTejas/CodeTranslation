#include<iostream>
using namespace std;
int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    if(a+b > 2*c){
        int num = min(x, y);
        x = x - num;
        y = y - num;
        ans = 2*c*num;
    }
    else{
        cout << a*x + b*y << endl;
        return 0;
    }
    if(a*x + b*y > 2*c*(x+y)) cout << ans + 2*c*(x+y) << endl;
    else cout << ans + a*x + b*y << endl;
    return 0;
}