#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

int x,y,z;

int main(){
    
    cin >> x >> y >> z;
    
    int L = x - z, set = y + z;
    
    int ans = L / set;

    cout << ans << endl ;
    
    return 0;
}
