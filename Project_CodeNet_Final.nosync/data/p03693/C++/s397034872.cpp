#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int tmp = 10*b + c;
    if(tmp % 4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}