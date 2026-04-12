//
//  main.cpp
//  tester
//
//  Created by Happiness on 2017/06/06.
//  Copyright © 2017年 Happiness. All rights reserved.
//


#include<iostream>
using namespace std;
int main(){
    int r,g,b,ans;
    cin >> r >> g >> b;
    ans = r*100+g*10+b;
    if(ans%4 != 0)cout << "NO" << "\n";
    else cout << "YES" << "\n";
    return 0;
}
