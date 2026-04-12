// SPDX-License-Identifier: Apache-2.0
// Copyright (C) 2020 Bjarni Dagur Thor Karason

#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); i++)
#define MP make_pair
#define PB push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
#define PI 3.14159265359

int n;
vi arr;
ll memo[3005][3005];

ll dp(int l, int r)
{
    if (memo[l][r] != -1) return memo[l][r];
    if (l == r) return arr[l];
    return memo[l][r] = max(arr[l] - dp(l + 1, r), arr[r] - dp(l, r - 1));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    memset(memo, -1, sizeof(memo));
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << dp(0, n - 1) << endl;

    return 0;
}