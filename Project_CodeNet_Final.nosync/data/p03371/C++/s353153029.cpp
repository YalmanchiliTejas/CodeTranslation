#include <iostream>
using namespace std;
long long a, b, c, x, y, count = 1000000000000;
int main(){
    cin >> a >> b >> c >> x >> y;

    for(int i=0;i<=2*max(x,y);i++) {
        int ma = (x-i/2)*a>0?(x-i/2)*a:0;
        int mb = (y-i/2)*b>0?(y-i/2)*b:0;
        count = min(count, c*i+ma+mb);
    }
    cout << count << endl;
    return 0;
}