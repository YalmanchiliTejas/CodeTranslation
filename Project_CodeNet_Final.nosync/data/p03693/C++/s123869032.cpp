#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    //freopen("test.in");
    int a,b,c;
    cin >> a >> b >> c;
    int d=100*a+10*b+c;
    if (d%4) cout << "NO" << endl;
     else cout << "YES" << endl;
}