#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int a, b, c, x, y, total_value=0;
    cin >> a >> b >> c >> x >> y;
    if(2 * c < a + b) {
        int less = min(x, y);
        total_value+=2*c*less;
        x-=less;
        y-=less;
        
    }
    if(x > 0) {
        if(2 * c < a) total_value += 2*c*x;
        else total_value += a*x;
    }
    if(y > 0) {
        if(2 * c < b) total_value += 2*c*y;
        else total_value += b*y;
    }
    cout << total_value << endl;
}
