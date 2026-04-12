//
//  second.cpp
//  CoderTest
//
//  Created by yuya on 2019/07/25.
//  Copyright © 2019 yuya. All rights reserved.
//

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(int (i) = 0; (i) < (int)(n); i++)
#define rep1(i,n) for(int (i) = 1; (i) <= (int)(n); i++)
#define INF 1000000
#define MOD (ll)(1e9 + 7)





int main()
{
    char c;
    int a=0,b=0;
    rep(i, 3){
        cin >> c;
        if(c=='A'){
            a=1;
        }
        if (c=='B') {
            b=1;
        }
    }
    
    if(a&&b){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    
    return 0;
}

