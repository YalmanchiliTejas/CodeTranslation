#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << (x) << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
ll len[51];
ll p[51];
ll solve(ll n,ll x){
    if(n==0)return 1;
    if(x == 1)return 0;
    if(x<=1+len[n-1])return solve(n-1,x-1);
    if(x<=len[n-1]+2)return p[n-1]+1;
    return p[n-1]+1+solve(n-1,x-len[n-1]-2);
}
int main(){
    ll n,x;
    cin >> n >> x;
    len[0] = 1;
    rep(i,50){
        len[i+1] = 2*len[i] + 3;
    }
    p[0] = 1;
    rep(i,50){
        p[i+1] = 2*p[i] + 1;
    }
    cout << solve(n,x) << endl;
}