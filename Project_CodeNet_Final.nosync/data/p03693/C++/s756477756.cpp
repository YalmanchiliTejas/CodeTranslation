#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
#include<math.h>
#include<vector>
#include<cctype>
#include<string>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
std::string line;

int main(){
    int r,g,b;
    cin >> r >> g >> b;

    int res = r*100 + g *10 + b;

    if((res%4) != 0) cout << "NO" << endl;
    else cout << "YES" << endl;
    
    return 0;
}