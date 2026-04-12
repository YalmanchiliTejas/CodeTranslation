#include <bits/stdc++.h>
using namespace std;

int a, b, c, x, y;

int main(){

    cin >> a >> b >> c >> x >> y;

    int price = 0, a_half, b_half, diff;
    diff = abs(x-y);

    if (a+b >= 2*c){
        price += min(x, y)*c*2;

        if (min(x, y) == x){
            if (b >= 2*c){
                price += diff*c*2;
            }
            else{
                price += diff*b;
            }
        }
        else{
            if (a >= 2*c){
                price += diff*c*2;
            }
            else{
                price += diff*a;
            }
        }
    }
    else{
        if (b >= 2*c){
            price += y*c*2;
        }
        else{
            price += y*b;
        }
        if (a >= 2*c){
            price += x*c*2;
        }
        else{
            price += x*a;
        }
    }

    cout << price << endl;
    return 0;
}