//
//  main.cpp
//  ProCon
//
//  Created by hashimotoryoma on 2017/08/20.
//  Copyright © 2017年 hashimotoryoma. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <vector>

#define repeat(i,n) for (int i = 0; (i) < (n); ++ (i))

using namespace std;

typedef long long ll;

int group(int n){
    if(n==2)
        return 2;
    else if(n==4 || n==6 || n==9 || n==11)
        return 1;
    else
        return 0;

}

int main() {
    // insert code here...    return 0;
    //////
    // input from txt
    /*
     std::ifstream in("input.txt");
     std::cin.rdbuf(in.rdbuf());
     std::ofstream out("output.txt");
     std::cout.rdbuf(out.rdbuf());
     ////
     */
    int r,g,b;
    cin >> r >> g >> b;
    cout <<((100*r+10*g+b)%4==0? "YES":"NO") << endl;
    return 0;
}
