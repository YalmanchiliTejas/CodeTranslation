//
//  main.cpp
//  Study
//
//  Created by 佐々木勇星 on 2020/03/12.
//  Copyright © 2020 佐々木勇星. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;


int main(int argc, const char * argv[]) {
    

    int n, m;
    string ans = "No";
    
    cin >> n >> m;
    
    if (n == m) ans = "Yes";
    
    cout << ans << endl;
    
    return 0;
}
