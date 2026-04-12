//header file---{{{
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
//end.header file---}}}
using namespace std;


//template---{{{
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b); i > (a); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)

#define all(i) (i).begin(), (i).end();
//end.template ---}}}

int main() {

    int A, B, C, X, Y;

    cin >> A >> B >> C >> X >> Y;

    int AB_piza_X = 0;
    int AB_piza_Y = 0;

    if (X > Y) {
        AB_piza_Y = Y;
    }
    else {
        AB_piza_X = X;
    }

    if (AB_piza_X != 0) {
        int formula[3];
        formula[0] = (A * X) + (B * Y);
        formula[1] = (AB_piza_X * 2 * C) + (Y - X) * B;
        formula[2] = Y * C * 2;

        sort(formula, formula + 3);

        cout << formula[0] << endl;

        return (0);
    }

    else if (AB_piza_Y != 0) {
        int formula[3];
        formula[0] = (A * X) + (B * Y);
        formula[1] = (AB_piza_Y * 2 * C) + (X - Y) * A;
        formula[2] = X * C * 2;

        sort(formula, formula + 3);

        cout << formula[0] << endl;
        return (0);
    }
/*
    if (AB_piza_X != 0) {
        if ((AB_piza_X * 2 * C) + (Y - X) * B < A * X + B * Y) {
            cout << (AB_piza_X * 2 * C) + (Y - X) * B << endl;
        }
        else {
        cout << A * X + B * Y << endl;
        }
    }
    else if (AB_piza_Y != 0) {
        if ((AB_piza_Y * 2 * C) + (X - Y) * A < A * X + B * Y) {
            cout << (AB_piza_Y * 2 * C) + (X - Y) * A << endl;
        }
        else {
            cout << A * X + B * Y << endl;
        }
    }
*/
}



