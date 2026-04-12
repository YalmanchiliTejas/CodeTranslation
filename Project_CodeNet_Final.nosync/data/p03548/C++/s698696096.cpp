#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define li long long int
#define FOR(i, a, b) for (li (i) = (a) ; (i) < (b) ; ++(i))
#define REP(i, n) FOR(i, 0, n)

int main(void) {
    li X, Y, Z;
    cin >> X >> Y >> Z;

    li left = X - Z;
    cout << left / (Y + Z);

    return 0;
}
