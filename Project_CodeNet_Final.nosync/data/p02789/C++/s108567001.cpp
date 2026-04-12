//
//  AC_or_WA.cpp
//  NYU Progteam
//
//  Created by Xinyu Qu on 2/21/20.
//  Copyright © 2020 Xinyu Qu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    
    if(M < N) cout << "No";
    else cout << "Yes";
    return 0;
}
