#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
typedef long long llong;
const int MOD=1000000007;

int main(int argc, char**argv){
    int r, g, b;
    cin >> r >> g >> b;
    int x = 100*r + 10*g + b;
    if (x % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
