#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int A,B,C,X,Y = 0;
    int min_price = 0;

    //A -> Aピザの枚数
    //B -> Bピザの枚数
    //C -> ABピザの枚数⇒2枚買えばAピザ1Bピザ1になる
    //X -> Aピザの必要枚数
    //Y -> Bピザの必要枚数
    cin >> A >> B >> C >> X >> Y;

    //A+B>2Cなら、X,Yのうち小さい数まではABピザで買うのが最小
    if( 2*C < (A+B) )
    {
        int lower_num = min(X,Y);
        min_price = C*(2*lower_num); //ABピザは2枚単位で買わないとA/Bピザを生成できない
        X = X - lower_num; //必要枚数更新
        Y = Y - lower_num; //必要枚数更新

        //残りはAピザ
        if(X > 0)
        {
            if( 2*C < A )
            {
                //ABピザ2枚の方が安いのでABピザで揃える
                min_price += C*2*X;
            }
            else
            {
                //個別に買う
                min_price += A*X;
            }

            X = 0; //必要枚数更新
        }
        
        //残りはBピザ
        if(Y > 0)
        {
            if( 2*C < B )
            {
                //ABピザ2枚の方が安いのでABピザで揃える
                min_price += C*2*Y;
            }
            else
            {
                //個別に買う
                min_price += B*Y;
            }

            Y = 0; //必要枚数更新
        }

        cout << min_price << endl;
        return 0;
    }

    //該当しない場合、それぞれ個別に買う
    min_price += A*X;
    min_price += B*Y;

    cout << min_price << endl;

    return 0;
}