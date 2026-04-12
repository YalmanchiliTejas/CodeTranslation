//
//  main.cpp
//  no.1
//
//  Created by MacBook_Virgo on 2015/04/23.
//  Copyright (c) 2015??´ MacBook_Virgo. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    while(cin >> n,n!=0){
    int max,min;
    max = 0;
    min = 1000;
    int x;
    int sum = 0;
    for(int i = 0;i <n;i = i+1){
        cin >> x;
        sum = sum + x;
        if(x >max){
            max = x;}
        if(x < min){
            min = x;}
    }
    cout << (sum - max - min) / (n-2) << endl;
    }return 0;
}