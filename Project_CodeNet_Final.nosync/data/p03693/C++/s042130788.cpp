#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <ctime>
#include <climits>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <cstdlib>

using namespace std;
long int pow107 = (int)pow(10, 9) + 7;
int ilimit = INT_MAX;
long int llimit = LONG_MAX;

bool comp(pair<int, string> a, pair<int, string> b){
    if(a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}

long int jou(long int x, long int y){
    long int f = 1;
    for(int i = 0; i < y; ++i){
        f = f * x % pow107;
    }
    return f;
}

bool pn(long int x){
    if(x != 2 && x % 2 == 0)
        return false;
    for(int i = 3; i < x; ++i){
        if(x != i && x % i == 0)
            return false;
    }
    return true;
}

long int factorial(long int n){
    long int f = 1;
    for(long int i = 1; i <= n; ++i){
        f = f * i % pow107;
    }
    return f;
}

//最大limit
//10^9+7    pow107
//素数pn
//n乗jou
//コンビネーションfactorial
//

int main(){
    int r;
    int t = 0;
    for(int i = 0; i < 3; ++i){
        cin >> r;
        t += r * (int)pow(10,2-i);
    }
    if(t % 4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}