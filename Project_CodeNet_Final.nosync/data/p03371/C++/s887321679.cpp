#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int min_cost = 2 * 5000 * 100000;
    for (int num_C = 0; num_C / 2 <= 100000; num_C++) {
        int num_A = 0, num_B = 0;
        if (num_C / 2 < X) {
            num_A = X - num_C / 2;
        }
        if (num_C / 2 < Y) {
            num_B = Y - num_C / 2;
        }
        int sum = A * num_A + B * num_B + C * num_C;
        min_cost = fmin(min_cost, sum);
    }
    cout << min_cost << endl;
    return 0;
}