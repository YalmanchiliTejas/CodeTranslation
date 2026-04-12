/*
 * written by Yaqi Zhang
 * University of Wisconsin-Madison
 * 2020
 */

#include<algorithm>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stdio.h>
#include<vector>

// #define INF 0x3f3f3f3f

using namespace std;

const int N = 2e5 + 10;

int nums[N];
int maxes[N];
const long long INF = 1e18;

map<pair<int, int>, long long> memo;


long long solve(int i, int j) {
    if (i <= 0) return -INF;
    if (2 * j > i + 2) return -INF;
    if (j == 0) return 0;
    if (j == 1) return maxes[i - 1];
    auto it = memo.find(make_pair(i, j));
    if(it != memo.end()) return it->second;
    long long ans = max(solve(i - 2, j - 1) + nums[i - 1], solve(i - 1, j));
    memo[make_pair(i, j)] = ans;
    return ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        nums[i] = x;
        if(i == 0) maxes[i] = x;
        else maxes[i] = max(x, maxes[i - 1]);
    }
    int m = n / 2;
    cout << solve(n, m) << "\n";
    return 0;

}

