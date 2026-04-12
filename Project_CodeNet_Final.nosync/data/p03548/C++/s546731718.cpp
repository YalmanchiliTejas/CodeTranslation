#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
    int x,y,z;
    cin >> x >> y >> z;
    x -= z;
    x /= y+z;
    cout << x << endl;
    return 0;
}