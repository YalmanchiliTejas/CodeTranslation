#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    cout << int(floor((x-z)/(y+z)));
}