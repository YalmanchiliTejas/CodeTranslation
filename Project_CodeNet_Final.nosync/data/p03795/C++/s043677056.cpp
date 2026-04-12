#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n,a,b;
    cin >> n;
    a = 800*n;
    b = (n/15)*200;
    cout << a-b << endl;

    return 0;
}