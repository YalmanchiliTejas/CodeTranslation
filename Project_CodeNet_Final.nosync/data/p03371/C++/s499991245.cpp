#define _USE_MAT_DEFINES
#include<iostream>
#include <iomanip>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <numeric>
#include <functional>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    cout << min({ A*X + B*Y,max(X,Y) * 2 * C,(X < Y) ? 2 * X*C + (Y - X)*B : 2 * Y*C + (X - Y)*A }) << endl;

    return 0;
}