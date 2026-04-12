//
// Created by Myabu on 2020/01/23.
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
#include <iomanip>

using namespace std;


int main(void){
    int X,Y,Z;

    cin>>X>>Y>>Z;

    int ans = 0;

    int temp = 0;
    temp += Z;
    while(true){
        if(temp > X)break;
        
        temp += Y+Z;
        
        
        if(temp <= X){
            ans++;
        }
        
    }

    cout<<ans<<endl;
    return 0;
}