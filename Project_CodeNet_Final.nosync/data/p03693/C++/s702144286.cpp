#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int main(){
    int a,b,c;
    string ans;
    cin >> a >> b >> c;
    if ((a*100+b*10+c)%4 == 0) {
        ans = "YES";
    }else{
        ans = "NO";
    }
    cout << ans << endl;
    
}