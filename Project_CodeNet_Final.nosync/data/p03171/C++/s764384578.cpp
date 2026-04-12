#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <fstream>
//#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
const ll INF = (1 << 30);
const ll inf = (1LL << 50LL);
const int  maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
int n;
ll arr[maxn];
ll dp[3005][3005][3];
ll rek(int levo, int desno, int turn){
    if(levo >= desno){
        if(turn == 0){
            return arr[levo];
        }
        return 0;
    }
    if(dp[levo][desno][turn] != -1){
        return dp[levo][desno][turn];
    }
    ll ret;
    if(turn == 0){
        ret = 0;
        ret = max(ret, rek(levo + 1, desno, 1 ^ turn) + arr[levo]);
        ret = max(ret, rek(levo, desno - 1, 1 ^ turn) + arr[desno]);
    }
    else{
        ret = inf;
        ret = min(ret ,rek(levo + 1, desno, 1 ^ turn));
        ret = min(ret, rek(levo, desno - 1, 1 ^ turn));
    }
    return dp[levo][desno][turn] = ret;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
     cin >> n;
    ll sum = 0;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        sum += arr[i];
    }
    memset(dp, -1, sizeof dp);
    ll A = rek(0, n - 1, 0);
    ll B = sum - A;
    cout << A - B << endl;
    return 0;
}
