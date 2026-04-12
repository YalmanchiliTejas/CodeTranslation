#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int a, b, c, x, y, price = 0;
    cin >> a >> b >> c >> x >> y;

    int min = (x < y ? x : y);
    if((a + b) / 2 >= c) price += c * 2 * min;
    else price += (a * min + b * min);

    if(x == y){
        printf("%d\n", price);
        return 0;
    }
    else if(x > y){
        if(a > c * 2) price += c * 2 * (x - y);
        else price += a * (x - y);
    }
    else{
        if(b > c * 2) price += c * 2 * (y - x);
        else price += b * (y - x);
    }

    printf("%d\n", price);
    return 0;
}
