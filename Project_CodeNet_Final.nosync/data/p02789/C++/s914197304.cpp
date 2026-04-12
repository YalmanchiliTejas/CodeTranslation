#include <iostream>
#include <cfenv>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <limits>

#define rep(i,n) for(int (i)=0;(i)<(n); ++(i))
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if ( n == m ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}