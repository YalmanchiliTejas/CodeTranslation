#include <iostream>

using namespace std;

int main(){

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int cost = 0;

    int common;
    if( x > y ){
        common = y;
    }else{
        common = x;
    }

    if( a + b < 2 * c){
        cost += ( a + b ) * common;
        x -= common;
        y -= common;
    }else{
        cost += 2 * c * common;
        x -= common;
        y -= common;
    }

    if( x > 0){
        if( a < 2 * c){
            cost += x * a;
        }else{
            cost += x * 2 * c;
        }
    }else{
        if( y > 0){
            if( b < 2 * c){
                cost += y * b;
            }else{
                cost += y * 2 * c;
            }
        }
    }

    cout << cost;

    return 0;
}
