#include <iostream>
#include <vector>
#include <algorithm>
#include<string>

using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    int cnt = 0;
    int cnt2 = 0;
    int res = 0;
    if(x % (y+z) == z){
        cout << x / (y+z) << endl;
    }else{
        cout << x / (y+z)-1 << endl;
    }
}