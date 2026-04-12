#include <bits/stdc++.h>
using namespace std;

#define P(s) cout << s << endl

int main() {
    int n;
    cin >> n;
    
    auto x = n * 800;
    auto y = (n / 15) * 200;
    
    P(x - y);
}