#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
using namespace std;
#define MAXSIZE 200
#define MAXL 100
typedef long long int lli;

int getDigitSum(int x);

int getAbs(int x);

int getMin(vector<int> v);

int main(){
    int x, y, z;
    cin >> x >> y >> z;

    int ans = (x - z) / (y + z);
    cout << ans << endl;
    return 0;
}

int getDigitSum(int x){
    int res = 0;
    while(x > 0){
        res += x % 10;
        x /= 10;
    }
    return res;
}

int getAbs(int x){
    return (x > 0)? x : -x;
}

int getMin(vector<int> v){
    int res = 40000;
    for(int i = 0; i < v.size(); i++){
        res = min(res, v[i]);
    }
    return res;
}