#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int main(){
    int r,g,b;
    cin >> r >> g >> b;

    int sum=r*100+10*g+b;

    if(sum%4==0) cout << "YES" << endl;
    else cout << "NO" << endl;
}