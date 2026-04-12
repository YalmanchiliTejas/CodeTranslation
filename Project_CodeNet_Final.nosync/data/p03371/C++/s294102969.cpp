#include <iostream>
using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int now_price;
    if (2*c - a - b <= 0){
        if (x > y and a < 2*c) now_price = 2*c*y + (x-y)*a;
        else if (x > y) now_price = 2*c*x;
        else if (x <= y and b < 2*c) now_price = 2*c*x + (y-x)*b;
        else now_price = 2*c*y;
    }else{
        now_price = a*x + b*y;
    }
    cout << now_price << endl;
}