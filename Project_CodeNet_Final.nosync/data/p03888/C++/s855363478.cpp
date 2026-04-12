#include <bits/stdc++.h>

using namespace std;
#define lint long long



int main() {
    double a, b;
    cin >> a >> b;
    
    double c;
    c = 1. / a + 1/ b;
    
    double d;
    d = 1. / c;
    
    constexpr int e = std::numeric_limits<float>::max_digits10;
    cout << setprecision(e) <<  1. / c << endl;
}