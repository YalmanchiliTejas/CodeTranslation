#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <limits.h>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    
    int r,g,b;
    int a;
    
    
    cin >> r;
    cin >> g;
    cin >> b;
    
    a = r*100 + g*10 + b;
    
    cout << (((a%4) == 0 ) ? "YES" : "NO") << endl;
    
    
    return 0;
}