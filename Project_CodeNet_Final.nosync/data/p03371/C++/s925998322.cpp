#include <iostream>
#include <stack>
using namespace std;

int main() {

    long A; //Aピザ 値段
    long B; //Bピザ 値段
    long C; //ハーフピザ 値段

    long X; //Aピザ 必要枚数
    long Y; //Bピザ 必要枚数

    // long x = 0;  //a枚数
    // long y = 0;  //b枚数
    // long z = 0; //ab枚数

    long goukei = 0;
    // 最小値を求める
    // (A * a_mai) + (B * b_mai) + (C * ab_mai) = goukei

    cin >> A >> B >> C >> X >> Y;

    // ハーフビザ2枚 = Aを1枚 + Bを1枚
    // 2C = A + B

    long saishou_mai = min(X, Y);
    long a_tarinai = 0;
    long b_tarinai = 0;
    long sa = X - Y;

    if (sa >= 0){
        a_tarinai = sa;
    }
    else{
        b_tarinai = abs(sa);
    }

    // 単体の方が安いパターン
    if ((2 * C) >= (A + B)){

        goukei = (A * saishou_mai) + (B * saishou_mai) + (A * a_tarinai) + (B * b_tarinai);
    }
    // ハーフの方が安いパターン
    else if ((2 * C) < (A + B)){

        //goukei = (2 * C * saishou_mai)+ (A * a_tarinai) + (B * b_tarinai);

        // A足りない
        if (sa >= 0){

            if ((A * a_tarinai) >= (2 * C * a_tarinai)){
                goukei = (2 * C * saishou_mai) + (2 * C * a_tarinai);
            }
            else {
                goukei = (2 * C * saishou_mai) + (A * a_tarinai);
            }

        }
        // Bが足りない
        else{

            if ((B * b_tarinai) >= (2 * C * b_tarinai)){
                goukei = (2 * C * saishou_mai) + (2 * C * b_tarinai);
            }
            else {
                goukei = (2 * C * saishou_mai) + (B * b_tarinai);
            }
        }
    }

    cout << goukei << endl;


    return 0;

}