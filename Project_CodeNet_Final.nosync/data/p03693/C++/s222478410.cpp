#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

int r, g, b;

int main(){
    cin >> r >> g >> b;
    int val = r*100 + g*10 + b;

    if(val % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}   
