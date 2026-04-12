#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
// #include <set>
// #include <cmath>
// #include <string>
// #include <map>
// #include <iomanip>

// #define MOD 1000000007

using namespace std;
// typedef unsigned long long ull;
typedef long long ll;

void p() {
    cout << "\n";
}
template<class Head, class... Body>
void p(Head head, Body... body) {
    cout << head << ",";
    p(body...);
}


int main(int argc, char const *argv[]) {
    int r, g, b;
    cin >> r >> g >> b;
    if ((g*10 + b) % 4 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
