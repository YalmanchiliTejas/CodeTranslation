#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long int

signed main(){
    int r,g,b;
    cin >> r >> g >> b;
    int num = r*100 + g*10 + b;
    cout << ((num%4==0) ? "YES" : "NO") << endl;
}