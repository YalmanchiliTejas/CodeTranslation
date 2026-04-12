//
//  main.cpp
//  A_RGBCards
//
//  Created by user1 on 2017/06/10.
//  Copyright © 2017年 user1. All rights reserved.
//


#include <iostream>
int r, g, b;

void solve(){
    std::cin >> r;
    std::cin >> g;
    std::cin >> b;
    
    if((r*100 + g*10+b)%4 == 0){
        printf("YES\n");
    }else printf("NO\n");
}

int main(int argc, const char * argv[]) {
    solve();
    return 0;
}
