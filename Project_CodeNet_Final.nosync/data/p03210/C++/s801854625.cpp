#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)

int main() {
    int x; cin >> x;
    if (x == 7 || x == 5 || x == 3)
    {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}