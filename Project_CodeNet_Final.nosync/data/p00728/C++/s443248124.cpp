//
//  main.cpp
//  no1
//
//  Created by Kae on 2015/04/23.
//  Copyright (c) 2015??´ Kae. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    while(cin >> n,n!=0){
    int max;
    int min;
    max = 0;
    min = 1005;
    int sum = 0;
    int x;
    for (int i = 0;i < n;i = i+1){
        cin >> x;
        sum = sum + x;
        if(x > max){
            max = x;}
        if(x < min){
            min = x;}
    }
    cout << (sum - max - min) / (n-2)<< endl;
    }return 0;
}