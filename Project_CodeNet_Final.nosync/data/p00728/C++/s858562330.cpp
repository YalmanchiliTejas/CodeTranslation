#include <iostream>
using namespace std;

int main()
{
    int i, n, input, sum, max, min;
    while (1) {
        cin >> n;
        if (n == 0) break;
        sum = 0;
        max = 0;
        min = 1000;
        for (i = 1; i <= n; i++) {
            cin >> input;
            sum += input;
            if (input > max) max = input;
            if (input < min) min = input;
        }
        cout << (sum - max - min) / (n - 2) << endl;
    }
}