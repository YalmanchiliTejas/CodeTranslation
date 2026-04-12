#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,c,x,y,costA,costB,costAB,buyA,buyB;
    cin >> a >> b >> c >> x >> y;

    if(a + b < 2 * c){
        costA = a * x;
        costB = b * y;
        cout << costA + costB << endl;
    }else{
        if(x < y){
            costA = 2 * c * x;
            costB = (y - x) * b;
            costAB = 2 * c * y;
            cout << min(costA+costB,costAB) << endl;
        }else{
            costB = 2 * c * y;
            costA = (x - y) * a;
            costAB = 2 * c * x;
            cout << min(costA+costB,costAB) << endl;
            }
        }


    return 0;
}