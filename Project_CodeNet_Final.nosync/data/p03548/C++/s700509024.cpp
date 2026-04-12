#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <string>
using namespace std;

int main(){
    int x,y,z;
    cin >> x >> y >> z;

    int ans = (x-z) /(y+z);
    cout << ans << endl;
}