#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<long long>;
using pll = pair<long long, long long>;
#define rep(i,n) for(long long i(0);(i)<(n);(i)++)

const string YES = "YES";
const string NO = "NO";

void solve(long long X){
    if(X == 3 || X == 5 || X == 7)
        cout << YES << endl;
    else
    {
        cout << NO << endl;
    }
    
}

int main(){
    long long X;
    scanf("%lld",&X);
    solve(X);
    return 0;
}
