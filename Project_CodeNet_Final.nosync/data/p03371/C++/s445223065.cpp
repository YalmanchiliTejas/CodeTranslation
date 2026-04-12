#include "bits/stdc++.h"

using namespace std;

#define COUNTOF(array) (sizeof(array) / sizeof(array[0]))

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int price = 0;
    int a_plus_b = a + b;
    int double_ab = c * 2;
    int min_double = min(a_plus_b, double_ab);

    int greedy_price = min_double * max(x, y);
    int num_of_needed_double = min(x, y);
    x -= num_of_needed_double;
    y -= num_of_needed_double;
    price += min_double * num_of_needed_double;
    price += x * a;
    price += y * b;
    price = min(price, greedy_price);
    cout << price << endl;
    return 0;
}

