#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    //int64_t value = 0;

    /* そのまま購入(最大値) */
    //value = (A*X) + (B*Y);

    /*  */
    // for(int i=X; i>=0; i--){
    //     for(int j=Y; j>=0; j--){
    //         int64_t tmp_value = (A*i) + (B*j);
    //         int64_t tmp = C * max( (X-i), (Y-j) ) * 2;
    //         tmp_value = tmp_value + tmp;
    //         value = min(value, tmp_value);
    //     }
    // }

    /*  */

    int64_t val = A*X + B*Y;

    for(int i=0; i<=max(X, Y); i++){

        int64_t tmp  = (C*i*2) + (A * max(X-i, 0)) + (B * max(Y-i, 0));
        val = min(val, tmp);
    }

    cout << val << endl;

}