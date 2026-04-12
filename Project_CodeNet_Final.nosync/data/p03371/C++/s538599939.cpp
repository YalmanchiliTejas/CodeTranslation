#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long a, b ,c, x, y;
    cin >> a >> b >> c >> x >> y;

    long long min_money = 1e12;
    long long X = x, Y = y;
    for(long long i = 0; i <= 100000; i++){
        long long now_money = 2*i*c;
       
        x = X - i;
        y = Y - i;
        if(x > 0){
            now_money += x*a;
        }
        if(y > 0){
            now_money += y*b;
        }

        min_money = min(min_money, now_money);

    }

    cout << min_money << endl;

    return 0;
}