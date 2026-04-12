//
// Created by Myabu on 2020/01/15.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <math.h>
#include <stack>
#include <queue>
#include <cstdio>
#include <numeric>

using namespace std;


int main(void){
    string c;
    cin>>c;

    string boin = "aiueo";

    if(boin.find(c) != string::npos){
        cout<<"vowel"<<endl;
    }else{
        cout<<"consonant"<<endl;
    }


    return 0;
}