#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const int mod = 1000000007;

/*
 * 全部A, B円で買って，減らしていく
 */

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int a = X, b = Y, c = 0;
    int price = a * A + b * B + c * C;
    if(A + B <= 2 * C){
        cout << price << endl;
        return 0;
    }else if(A + B > 2 * C){
        while(true) {
            int new_price = price;
            new_price += 2 * C;
            if (a != 0) {
                a -= 1;
                new_price -= A;

            }
            if (b != 0) {
                b -= 1;
                new_price -= B;
            }
            if(new_price >= price){
                break;
            }else{
                price = new_price;
            }
        }
    }else{
        cout << "error" <<endl;
        return 0;
    }
    // debug
    // cout << "a:" << a << " b:" << b << " c:" << c << endl;
    cout << price << endl;




}
