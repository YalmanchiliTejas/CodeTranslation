#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int sum1 = 0, sum2 = 0, sum3 = 0;
    sum1 = a * x + b * y;
    if(x <= y){
        sum2 = 2 * c * x + b * (y - x);
        sum3 = 2 * c * y;
    }
    else{
        sum2 = 2 * c * y + a * (x - y);
        sum3 = 2 * c * x;
    }

    int sum = min(min(sum1, sum2), min(sum2, sum3));
    cout << sum << endl;

    return 0;
}