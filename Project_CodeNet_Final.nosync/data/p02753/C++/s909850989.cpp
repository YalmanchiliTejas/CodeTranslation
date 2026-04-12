//
//  main.cpp
//  ABC159
//
//  Created by 安藤光希 on 2020/04/20.
//  Copyright © 2020 安藤光希. All rights reserved.
// https://atcoder.jp/contests/abc158


#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i<n; i++)
using namespace std;
typedef long long ll;

int main() {
    string S;
    cin >> S;
    string r = "No";
    
    if (S[0] != S[1] | S[0] != S[2]){
        r = "Yes";
    }
    cout << r << endl;
}

/* A
 
 */
