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
#include <deque>
#include <numeric>
using namespace std;

int main() {
    int N, ans = 0, max_ = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        if (max_ <= h)ans++;
        max_ = max(max_, h);
    }

    cout << ans << endl;

    return 0;
}