#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <regex>
#include <map>
#include <set>
#include <iomanip>

using namespace std;
#define int long long

signed main(){
    int r,g,b;
    cin >> r >> g >> b;
    
    int ans = 0;
    ans = r*100+g*10+b;

    if(ans%4==0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
    return 0;
}
