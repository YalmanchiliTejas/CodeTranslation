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
    int r,g,b; cin >> r >> g >> b;
    if ((g*10 + b) % 4 == 0) cout << "YES\n";
    else  cout << "NO\n";
    return 0;
}