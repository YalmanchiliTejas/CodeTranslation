#include <bits/stdc++.h>
#include <numeric>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int r,g,b;
    cin >> r >> g >> b;
    cout << ((r*100+g*10+b)%4==0?"YES":"NO") << endl;
}
