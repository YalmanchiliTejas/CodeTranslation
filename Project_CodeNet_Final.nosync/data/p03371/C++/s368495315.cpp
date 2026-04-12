#include<iostream>

using namespace std;

int main(){

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    if(a+b<=2*c){
        cout << a * x + b * y << endl;
    }
    else{
        int ans = 0;
        if (x < y)
        {
            ans += 2 * c * x;
            if(b<2*c){
                ans += (y - x) * b;
            }
            else{
                ans += (y - x) * 2 * c;
            }
        }
        else{
            ans += 2 * c * y;
            if(a<2*c){
                ans += (x - y) * a;
            }
            else{
                ans += (x - y) * 2 * c;
            }
        }
        cout << ans << endl;
    }

    return 0;
}