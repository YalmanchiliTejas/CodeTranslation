#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int total_cost = A * X + B * Y;
    //cout << total_cost << endl;
    int big = max(X, Y);
    int small = min(X, Y);

    int tc1;
    if (big == X) {
        tc1 = big * C * 2;
    } else {
        tc1 = big * C * 2;
    }
    //cout << tc1 << endl;
    total_cost = min(tc1, total_cost);

    int tc2;
    if (small == X) {
        tc2 = small * C * 2 + (big - small) * B;
    } else {
        tc2 = small * C * 2 + (big - small) * A;
    }
    //cout << tc2 << endl;
    total_cost = min(tc2, total_cost);

    cout << total_cost << endl;
	
    return 0;
}