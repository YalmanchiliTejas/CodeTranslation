#include <iostream>
#include <math.h>

using namespace std;

unsigned long long  min(unsigned long long  x, unsigned long long  y) {
    if (x>y)
        return y;
    return x;
}

unsigned long long  max(unsigned long long  x, unsigned long long  y) {
    if (x<y)
        return y;
    return x;
}

int main() {
    unsigned long long  A,B,C,X,Y;
    unsigned long long  res = 0;
    cin >> A >> B >> C >> X >> Y;

    unsigned long long minim;
    if ((double) C < (double)(A + B) / 2)
    {
        minim = min(X, Y);
        res = minim * C * 2;
        X -= minim;
        Y -= minim;
        if (X != 0)
        {
            if (C < A / 2)
                res += X * C * 2;
            else
                res += X * A;
        }
        else if (Y != 0)
        {
            if (C < B / 2)
                res += Y * C * 2;
            else
                res += Y * B;
        }
    }
    else
    {
        res = X * A;
        res += Y * B;
    }

   /* if (C < min(A,B)/2) {
        res = max(X,Y)*2 * C;
    } else {
        if (C < (A+B)/2) {
            res = min(X,Y)C2;
            if (X>Y) {
                res += (X-Y) * A;
            } else {
                res += (Y-X) * B;
            }
        } else {
            res = XA + YB;
        }
    }*/

    cout << res;
}