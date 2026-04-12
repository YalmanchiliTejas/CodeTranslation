#define _USE_MATH_DEFINES // for C++  
#include <cmath> 
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <iterator>
#include <utility>
#include <set>
#include <random>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <functional>
#include <bitset>
#define LL long long

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a*100+b*10+c)%4==0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
} 