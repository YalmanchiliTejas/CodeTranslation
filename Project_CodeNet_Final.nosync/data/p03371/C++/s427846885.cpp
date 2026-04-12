#include <iostream>
using namespace std;

int main()
{
    int A, B, C, X, Y;
    int Xnum = 0;
    int Ynum  = 0;
    int Cnum = 0;
    cin >> A >> B >> C >> X >> Y;
    if((A + B) <= (2 * C)) {
        /* バラ売りを買う */
        Xnum = X; Ynum = Y;
    }
    else {
        /* ABとして買える分をすべて買う */
        if(X > Y) {
            Cnum = Y * 2;
            X = X - Y;
            if((2 * C) < A) {
                /* すべてABピザとなるパターン */
                Cnum += (X * 2);
            }
            else {
                Xnum = X;
            }
        }
        else {
            Cnum = X * 2;
            Y = Y - X;
            if((2 * C) < B) {
                /* すべてABピザとなるパターン */
                Cnum += (Y * 2);
            }
            else {
                Ynum = Y;
            }
        }
    }
    cout << (Xnum * A) + (Ynum * B) + (Cnum * C) << endl;

    return 0;
}
