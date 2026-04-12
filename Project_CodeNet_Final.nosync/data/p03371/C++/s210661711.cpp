#include<iostream>
using namespace std;

int a, b, c, x, y;

int main(){
    cin >> a >> b >> c >> x >> y;
    if(a + b < c * 2){
        cout << a * x + b * y << endl;
    }else{
        if(a < c){
            if(x < y){
                cout << c * x * 2 + b * (y - x) << endl;
            }else{
                cout << a * (x - y) + c * y * 2 << endl;
            }
        }else if(b < c){
            if(y < x){
                cout << c * y * 2 + a * (x - y) << endl;
            }else{
                cout << b * (y - x) + c * x * 2 << endl;
            }
        }else{
            if(x < y){
                if(a > b){
                    cout << min(c * 2 * y, b * (y - x) + c * x * 2) << endl;
                }else{
                    cout << min(c * 2 * y, c * x * 2 + b * (y - x)) << endl;
                }
            }else{
                if(a < b){
                    cout << min(c * 2 * x, a * (x - y) + c * y * 2) << endl;
                }else{
                    cout << min(c * 2 * x, c * y * 2 + a * (x - y)) << endl;
                }
            }
        }
    }
    return 0;
}