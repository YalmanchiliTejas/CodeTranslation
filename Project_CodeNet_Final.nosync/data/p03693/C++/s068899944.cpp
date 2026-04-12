#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    // input
    char r, g, b; cin >> r >> g >> b;
    // compute
    string S;
    S = S + r + g + b;
    int num = atoi(S.c_str());
    if(num % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    // output
}