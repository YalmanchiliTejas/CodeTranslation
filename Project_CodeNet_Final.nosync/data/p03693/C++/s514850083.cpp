#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

template <typename T>
T gcd(T a, T b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

template <typename T>
T lcm(T a, T b) {
    T g = gcd(a, b);
    return a / g * b;
}

int main(){

    int r, g, b;
    cin >> r >> g >> b;

    int num = 100 * r + 10 * g + b;
    if(num % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}