#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    int X, Y;
    int a, b, c;
    int x, y;
    int min;
    int tmp;
    int gt;
    cin >> A >> B >> C >> X >> Y;

    if(A < C && B < C) {
        cout << (A*X)+(B*Y) << endl;
        return 0;
    }

    if(X > Y) {
        gt = X<<1;
    } else {
        gt = Y<<1;
    }

    min = 1000000000;
    if(C < A && C < B) {
        if(X > Y) {
            c = Y;
        } else {
            c = X;
        }
    } else {
        c = 0;
    }
    for(; c <= gt; c++) {
        if((X-c/2) > 0) {
            a = X-c/2;
        } else {
            a = 0;
        }
        for(; a <= X; a++) {
            if((Y-c/2) > 0) {
                b = Y-c/2;
            } else {
                b = 0;
            }
            for(; b <= Y; b++) {
                tmp = A*a + B*b + C*c;
                //cout << tmp << ", " << a << ", " << b << ", " << c << endl;
                if((a+c/2) >= X && (b+c/2) >= Y) {
                    if(tmp <= min) {
                        //cout << tmp << ", " << a << ", " << b << ", " << c << endl;
                        min = tmp;
                    }
                    break;
                }
            }
            if((a+c/2) >= X && (b+c/2) >= Y) {
                break;
            }
        }
    }

    cout << min << endl;;

    return 0;
}