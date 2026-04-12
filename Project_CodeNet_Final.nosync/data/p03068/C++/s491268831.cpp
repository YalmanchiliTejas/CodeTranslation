#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<array>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){

    int n;
    string s;
    int k;

    cin >> n >> s >> k;

    for(int i = 0; i < n; ++i){
        if(s[i] != s[k-1])s[i] = '*';
    }

    cout << s << endl;

    return 0;
}