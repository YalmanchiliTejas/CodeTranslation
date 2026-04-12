#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
using namespace std;
int main(){
    int r,g,b;
    string ans = "NO";
    cin >> r >> g >> b;
    int num = 100*r+10*g+b;
    if(num%4==0){
        ans = "YES";
    }
    cout << ans << endl;
}