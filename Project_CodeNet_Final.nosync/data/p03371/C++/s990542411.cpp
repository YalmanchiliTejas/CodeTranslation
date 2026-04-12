#include <iostream>
using namespace std;


int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int min = a*x + b*y;
    for(int i=0; i<=x || i<=y; i++){
        int ap, bp, cp;
        ap = x < i ? 0 : a*(x-i);
        bp = y < i ? 0 : b*(y-i); 
        cp = 2*c*i;
        if( ap + bp + cp < min ){
            min = ap + bp + cp;
        }
    }

    cout << min << endl;

    return 0;
}