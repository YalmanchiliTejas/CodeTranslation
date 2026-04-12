#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i = 0; i , (n); ++i)
using ll = long long;
using namespace std;
int sum(int n) {
    if (n == 0) {
        return 0;
    }

    int s = sum(n - 1);
    return s + n;
}
int main() {
    int X;
    cin >> X;
    if (X >= 30) {
        cout << "Yes";
    }
    else cout << "No";
}
