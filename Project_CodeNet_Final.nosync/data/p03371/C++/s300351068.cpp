#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    if((a + b) > c * 2) {
        int sum = 0;
        if(x > y){
            sum += c * 2 * y;
            if(a > c * 2){
                sum += (x - y) * (c*2);
            }
            else{
                sum += (x - y) * a;
            }
            cout << sum << endl;
            return 0;
        }
        else{
            sum += c * 2 * x;
            if( b > c * 2 ){
                sum += (y - x) * (c*2);
            }
            else{
                sum += (y - x) * b;
            }
            cout << sum << endl;
            return 0;
        }
    }

    else{
        cout << a * x + b * y << endl;
        return 0;
    }
}
