#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <map>
#include <vector>
#include <unordered_map>

#define div 1000000000+7

using ll = long long;
using namespace std;

void solve() {
    int r, g, b;
    cin >> r >> g >> b;
    int num = r * 100 + g * 10 + b;
    if(num%4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main() {
    solve();
    return 0;
}
