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
    int h,w;cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; i++) {
        cin >> a[i];
    }
    
    vector<bool> row(h, false);
    vector<bool> col(w, false);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    
    for (int i = 0; i < h; i++) {
        if (row[i]) {
            for (int j = 0; j < w; j++) {
                if (col[j]) {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
}


