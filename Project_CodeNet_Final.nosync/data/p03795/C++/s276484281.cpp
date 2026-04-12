#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
long long MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    int x = n * 800;
    int y = static_cast<int>(n/15) * 200;
    cout << x-y << "\n";
    return 0;
}