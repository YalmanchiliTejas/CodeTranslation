//
//  main.cpp
//  ABC_095_C
//
//  Created by Joe Mori on 2020/06/28.
//  Copyright © 2020 Joe Mori. All rights reserved.
//

#include <iostream>
#include<vector>

int main(int argc, const char * argv[]) {
    // insert code here...
    long long int A,B,C,X,Y,count;
    std::cin>>A>>B>>C>>X>>Y;
    count=A*X+B*Y+2*C*(X+Y);
    long long int zero=0;
    for(long long int i=0;i<=std::max(X,Y);i++){
        count=std::min(count,C*2*i+A*std::max((X-i),zero)+B*std::max((Y-i),zero));
    }
    std::cout<<count<<std::endl;
    return 0;
}
