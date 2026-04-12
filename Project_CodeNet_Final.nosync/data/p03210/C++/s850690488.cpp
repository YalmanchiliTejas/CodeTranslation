//g++ -std=c++11 -Wall -O2 -o main.exe main.cpp
//g++ -std=c++14 -Wall -O2 -o main.exe main.cpp

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <tuple>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>

using namespace std;

#define spc " "
#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p_ii;
typedef tuple<int, int, int, int> tup;

ll divc(ll a, ll b){ //割り算(切り上げ)
    return (a + b - 1) / b;
}

//------------------------------------------------------------------------------

int main(){
    int n;
    cin >> n;
    if(n == 3 || n == 5 || n == 7) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}