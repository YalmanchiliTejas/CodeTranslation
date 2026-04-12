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
ll INF = 1LL << 60;

void solve(long long A, long long B, long long C, long long X, long long Y){
    ll ans = INF;
    ll money, minXY = min(X, Y), maxXY = max(X, Y);
    //* method 1
    money = minXY * 2 * C + (X-minXY)*A + (Y-minXY)*B;
    ans = min(ans, money);
    //* method 2
    money = X * A+ Y * B;
    ans = min(ans, money);
    //* method 3
    money = maxXY * 2 * C;
    ans = min(ans, money);

    cout << ans << endl;
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long C;
    scanf("%lld",&C);
    long long X;
    scanf("%lld",&X);
    long long Y;
    scanf("%lld",&Y);
    solve(A, B, C, X, Y);
    return 0;
}
