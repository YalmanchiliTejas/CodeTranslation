#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int A;
    int B;
    int C;
    int X;
    int Y;

    cin >> A;
    cin >> B;
    cin >> C;
    cin >> X;
    cin >> Y;

    int ab_num;
    int kaitasi;
    int ookii;

    if(A + B <= C * 2) {
        cout << A * X + B * Y << endl;
    } 
    else {
        if(X <= Y) {
            ab_num = X;
            ookii = Y;
            kaitasi = B * (Y - X);
        }
        else{
            ab_num = Y;
            ookii = X;
            kaitasi = A * (X - Y);
        }

        int answer1 = 2 * C * ookii;
        int answer2 = 2 * C * ab_num + kaitasi;

        if(answer1 <= answer2) {
            cout << answer1<< endl;
        }
        else {
            cout << answer2<< endl;
        }
    }
}