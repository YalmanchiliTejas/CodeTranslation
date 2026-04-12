#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i,a,b) for(int i=int(a);i<int(b);i++)

using namespace std;

typedef long long int lli;

int main () {
    int r, g, b;
    cin >> r >> g >> b;
    int num = r * 100 + g * 10 + b;
    cout << (num % 4 == 0 ? "YES" : "NO") << endl;
    return 0;
}
