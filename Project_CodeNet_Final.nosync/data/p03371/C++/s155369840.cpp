#include <iostream>
using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = 1001001001;
    for(int ab = 0; ab <= 2*x || ab <= 2*y; ab += 2){
        int coans = ab*c;
        if((x-ab/2)*a > 0) coans += (x-ab/2)*a;
        if((y-ab/2)*b > 0) coans += (y-ab/2)*b;
        if(ans > coans) ans = coans;
    }

    cout << ans << endl;
    return 0;
}