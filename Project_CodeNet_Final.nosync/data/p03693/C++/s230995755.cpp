#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a , b , c;
    cin >> a >> b >> c;
    if( ( 100 * a + 10 * b + c ) % 4 == 0 ) cout << "YES";
    else cout << "NO";
}
