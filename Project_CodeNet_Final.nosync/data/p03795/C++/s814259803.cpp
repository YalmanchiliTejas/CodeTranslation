#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cctype>

#define div 1000000000+7

typedef long long ll;

using namespace std;


int main() {
    int n, ans;
    cin >> n;
    ans = 800 * n - 200 * (n/15);
    cout << ans << endl;
}