    //
    //  main.cpp
    //  study_c++
    //
    //  Created by Hisaki Kobayashi on 2020/03/31.
    //  Copyright © 2020 Hisaki Kobayashi. All rights reserved.
    //

    #include <iostream>
    #include <stdio.h>
    #include <string>
//    #include <bits/stdc++.h>
#include <bits/stdc++.h>

    using namespace std;

    int main(int argc, const char * argv[]) {
        long long A,B,C,X,Y;
        cin >> A >> B >> C >> X >> Y;
        long long k;
        long long sum=10000000000000,temp=0;
        for(k=0;k<=max(X,Y);k++){
            temp = 2*k*C +max(0LL,(X-k))*A +max(0LL,Y-k)*B;
            sum = min(sum,temp);
        }
        cout << sum << endl;

    }
