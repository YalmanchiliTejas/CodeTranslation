#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)n;i++)

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    cout << (X - Z)/(Y+Z) << endl;
}