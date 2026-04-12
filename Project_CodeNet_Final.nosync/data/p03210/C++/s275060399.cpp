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
#include <cmath>
#include <tuple>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;

int dy[4] = {-1, 0, +1, 0};
int dx[4] = {0, +1, 0, -1};

const long long INF = 1LL << 60;
const ll MOD = 1e9 + 7;

bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}

int gcd(int a, int b){
	if (b == 0)return a;
	return gcd(b, a % b);
}

//-----------------------ここから-----------


int main(void){
    int x;
    cin >> x;

    if(x == 7 || x == 5 || x == 3){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

