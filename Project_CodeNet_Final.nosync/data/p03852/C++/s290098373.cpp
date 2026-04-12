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
    char c;
    cin >> c;
    cout << ((c=='a'||c=='i'||c=='u'||c=='e'||c=='o')? "vowel":"consonant")<<endl;
    return 0;
}
