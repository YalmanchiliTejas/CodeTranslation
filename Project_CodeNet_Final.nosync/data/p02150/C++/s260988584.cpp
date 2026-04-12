#include<bits/stdc++.h>
using namespace std;
int M = 1000000007;

int main() {
    long long a,b,x;
    cin >> a >> b >> x;
    if (x < a) {
        cout << x % M << "\n";
    }
    else {
        cout << (((x - a) / (a - b) + 1) % M * (b % M) % M + x) % M << '\n';
    }
    return 0;
}

