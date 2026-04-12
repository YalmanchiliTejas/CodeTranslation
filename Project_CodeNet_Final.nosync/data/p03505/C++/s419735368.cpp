//
//  main.cpp
//  A - Kaiden
//
//  Created by wenhan on 2017/11/26.
//  Copyright © 2017年 wenhan. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long long k,a,b;
    cin>>k>>a>>b;
    if(k==0)
        cout<<0<<endl;
    else if(a<=b&&k-a>0)
        cout<<-1<<endl;
    else{
         long long s,t=1;
        if(k-a>0){
            s=k-a;
            t+=2*(s/(a-b));
            if(s%(a-b)!=0)
                t+=2;
        }
        cout<<t<<endl;
    }
    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}
