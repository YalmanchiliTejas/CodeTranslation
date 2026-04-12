/*
これを入れて実行
g++ code.cpp
./a.out
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <tuple>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;

int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const long long INF = 1LL << 60;
const ll MOD = 1e9 + 7;

bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}

int gcd(int a, int b){
	if (b == 0)return a;
	return gcd(b, a % b);
}

ll nCm(ll n, ll m){
    if (m == 0 || m == n)
        return (1);
    else if (m == 1)
        return (n);
    return (nCm(n - 1, m) + nCm(n - 1, m - 1));
}

//-----------------------ここから-----------

int main(void){
    int x, y, z;
    cin >> x >> y >> z;

    cout << (x - z) / (y + z) << endl;
}