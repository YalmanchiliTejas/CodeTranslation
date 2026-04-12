#include <iostream>

using namespace std;

int main() {
    int a,b,c,x,y; cin >> a >> b >> c >> x >> y;
    if((a+b) > 2*c) {
        if(x > y)
            cout << y*2*c + (x-y)*min(a,2*c) << endl;
        else
            cout << x*2*c + (y-x)*min(b,2*c) << endl;
    } else {
        cout << a*x + b*y << endl;
    }
}
