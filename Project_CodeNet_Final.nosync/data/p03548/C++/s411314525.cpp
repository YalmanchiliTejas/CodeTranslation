//
//  main.cpp
//  AC
//
//  Created by makinofuya on 2019/07/08.
//  Copyright © 2019 makinofuya. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <math.h>

typedef long long ll;
using namespace std;
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
#define out(s) cout << s << endl


int main(){
    int x,y,z;cin >> x >> y >> z;
    int w=y+z;
    x-=z;
    cout << x/w << endl;
    return 0;
}
