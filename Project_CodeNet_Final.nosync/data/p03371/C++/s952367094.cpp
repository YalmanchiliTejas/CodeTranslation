#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

long long GCD(long long a, long long b){if(b==0)return a;return GCD(b,a%b);}

int main() {

    int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;

    long long res = 0;

    for (int i = 0; i < min(X, Y); i++) {
        res += min (A+B, C*2);
    }

    if (X > Y) {
        res += (X - Y) * min(A, C*2);
    } else {
        res += (Y - X) * min(B, C*2);
    } 

    cout << res << endl;
}
