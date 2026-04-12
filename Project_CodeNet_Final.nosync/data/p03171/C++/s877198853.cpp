/*
 * written by Yaqi Zhang
 * University of Wisconsin-Madison
 * 2020
 */

#include<algorithm>
#include<cstring>
#include<climits>
#include<iostream>
#include<map>
#include<set>
#include<stdio.h>
#include<vector>

#define INF 0x3f3f3f3f
typedef long long ll;

using namespace std;

const int N = 3005;

long long memo[N][N];

int nums[N];

long long pre_nums[N];


long long solve(int lo, int hi) {
    if(lo > hi) return 0;
    if(lo == hi) return nums[lo];
    if(memo[lo][hi] != -1) return memo[lo][hi];
    long long total = pre_nums[hi + 1] - pre_nums[lo];
    long long ans = max(total - solve(lo + 1, hi), total - solve(lo, hi - 1));
    memo[lo][hi] = ans;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> nums[i];
    memset(memo, -1, sizeof memo);
    long long sum = 0LL;
    for(int i = 0; i < n; ++i) sum += nums[i];
    for(int i = 1; i < n + 1; ++i) pre_nums[i] = pre_nums[i - 1] + nums[i - 1];
    long long ans = solve(0, n - 1);
    cout << ans - (sum - ans) << endl;
    return 0;
}
