#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

int main() {

    long A, B, C; // それぞれの値段 
    long X, Y;    // 必要枚数

    cin >> A >> B >> C >> X >> Y;

    // 2C = A + B

    long kyotsu_mai = min(X, Y);
    long saidai_mai = max(X, Y);
    long tarinai = 0;
    if(X > Y){
        tarinai = X - kyotsu_mai;
    }else{
        tarinai = Y - kyotsu_mai;
    }

    //cout << "kyotsu_mai: " << kyotsu_mai <<endl;
    //cout << "tarinai   : " << tarinai << endl;

    long sum = 0;

    //まとめ買いが安い
    if (2 * C  < A + B){

        //int sum = 0;
        sum += (2 * C) * kyotsu_mai;
        //cout << "sum 01   : " << sum << endl;
        if(X > Y){
            
            sum += tarinai * A;
            //cout << "sum 02   : " << sum << endl;
        }
        else{
            
            sum += tarinai * B;
            //cout << "sum 03   : " << sum << endl;
        }

        int sum_2 = saidai_mai * (2 * C);
        if (sum > sum_2){
            sum = sum_2;
        }

    }else if (2 * C >= A + B){

        //int sum = 0;
        sum += A * X + B * Y ;

    }



    cout << sum << endl;




}