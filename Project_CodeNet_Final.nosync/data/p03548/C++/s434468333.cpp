#include <bits/stdc++.h>
using namespace std;

bool is_squere(long N) {
        long r = (long) floor(sqrt(N));
        return (r * r) == N;
}

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    int l = 0, n = 0;


    for(int i = 0; ; i++) {
        l += Z + Y;
        if(l + Z > X) {
            break;
        }
        n++;
    }
    cout << n << endl;
}