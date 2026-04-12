#include <iostream>
using namespace std;

int main() {
    int A, B, C, X, Y;
    long long max = 2 * 100005;
    cin >> A >> B >> C >> X >> Y;

    long long min_price = max * 5000;
    for(long long i=0; i<=max; i+=2) {
        long long num_X, num_Y;
        if (X < i/2) num_X = 0;
        else num_X = (X-i/2);
        if (Y < i/2) num_Y = 0;
        else num_Y = (Y-i/2);
        long long price = C * i + A * num_X + B * num_Y;
        if(price < min_price) min_price = price;
    } 
    cout << min_price << endl;
}