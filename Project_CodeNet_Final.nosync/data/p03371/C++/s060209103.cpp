#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    long long x, y;
    long long ans = 0;
    cin >> a >> b >> c >> x >> y;
    if(a+b > 2*c){
        while(x*y != 0){
            ans += 2*c;
            x--;
            y--;
        }
    }
    if(a > 2*c){
        ans += x*c*2;
        x = 0;
    }
    if(b > 2*c){
        ans += y*c*2;
        y = 0;
    }
    ans += a*x + b*y;
    cout << ans << endl;
}