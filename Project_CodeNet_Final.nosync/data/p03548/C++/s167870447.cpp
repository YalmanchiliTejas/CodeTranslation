#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
#define ull unsigned long long
#define ll long long
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x,y,z;
    cin >> x >> y >> z;
    cout << (x-z)/(y+z) << endl;

    return 0;
}
