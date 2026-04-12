/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
#include <bitset>
 
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
 
ll gcd(ll a, ll b){
	if (b == 0)return a;
	return gcd(b, a % b);
}
 
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
 
ll nCr(ll n, ll r){
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
 
//-----------------------ここから-----------
ll tSize[55];
ll pNum[55];
ll n, x;
ll ans = 0;

void solve(ll nowp, ll nows){
    if(tSize[nows] / 2 + 1 <= nowp){
        ans += pNum[nows - 1];
        //cout << pNum[nows - 1] << endl;
        ans++;
        if(tSize[nows] / 2 + 1 == nowp){
            return;
        }
        ll nextp = nowp - (tSize[nows] / 2 + 1);
        if(nows < 1) return;
        solve(nextp, nows - 1);
    } else {
        if(nowp - 1 < 1){
            return;
        }
        if(nows < 1) return;
        solve(nowp - 1, nows - 1);
    }
    


}

int main(void){
    cin >> n >> x;
    tSize[0] = 1;
    pNum[0] = 1;
    for(int i = 1; i <= n; i++){
        tSize[i] = tSize[i - 1] * 2 + 3;
        //cout << tSize[i] << endl;
        pNum[i] = pNum[i - 1] * 2 + 1;
    }

    solve(x, n);

    cout << ans << endl;
}