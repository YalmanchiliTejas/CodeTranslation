#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
int main (){
    int x,y,z;
    int count = 0;
    cin >> x >> y >> z;
    x -= z*2;
    while (1){
        x -= y+z;
        if (x<0) {
            if (x+z>=0) count++;
            break;
        }
        count++;
    }
    cout << count << endl;
    return 0;
}

