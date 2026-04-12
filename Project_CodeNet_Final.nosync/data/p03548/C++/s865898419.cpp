//
//  main.cpp
//  20190815lesson
//
//  Created by Priscilla Leang on 8/15/19.
//  Copyright © 2019 Priscilla Leang. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int x, y, z, f, m;
    cin>> x >> y >> z;
    x = x - z;
    f = y + z;
    m = x /f;
    cout << m;
    return 0;
}
