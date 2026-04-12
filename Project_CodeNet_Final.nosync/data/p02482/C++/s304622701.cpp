//
//  main.cpp
//  AizuOnlineJudge
//
//  Created by TomoyaYamaguchi on 2016/06/18.
//  Copyright ?? 2016??´ TomoyaYamaguchi. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    using namespace std;
    int a;
    int b;
    
    cin >> a >> b;
    
    if(a > b){
        cout << "a > b" << endl;
    }else if(a < b){
        cout << "a < b" << endl;
    }else{
        cout << "a == b" << endl;
    }
    
    return 0;
}