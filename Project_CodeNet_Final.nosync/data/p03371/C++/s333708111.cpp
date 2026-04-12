#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){

    int price[3];
    int x, y;

    for(int i = 0; i < 3; i++) cin >> price[i];
    cin >> x;
    cin >> y;

    if(price[0] + price[1] < 2 * price[2]){
        cout << price[0] * x + price[1] * y << endl;
    }
    else{
        if(x < y){
            cout << min( 2 * price[2] * x + price[1] * (y - x), 2 * price[2] * y ) << endl;
            //cout << "tes1" << endl;

        }
        else if(x >= y){
            cout << min( 2 * price[2] * y + price[0] * (x - y), 2 * price[2] * x ) << endl;
            //cout << "tes" << endl;
        }
    }

}