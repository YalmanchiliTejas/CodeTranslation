//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

//ifstream cin("x.in"); ofstream cout("x.out");

deque< int > d;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        int x;
        cin >> x;

        if (i % 2) {
            d.push_back( x );
        } else {
            d.push_front( x );
        }
    }

    if (n % 2 == 0) {
        while (!d.empty()) {
            cout << d.front() << " ";
            d.pop_front();
        }
    } else {
        while (!d.empty()) {
            cout << d.back() << " ";
            d.pop_back();
        }
    }

    return 0;
}
