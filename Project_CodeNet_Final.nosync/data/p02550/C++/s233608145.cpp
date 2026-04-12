#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <tuple>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <random>
#include <set>
#include <stack>
#include <time.h>

//#include <bits/stdc++.h>
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,i0,n) for(int (i)=(i0);(i)<(n);(i)++)
#define FORR(i,i0,n) for(int (i)=(n)-1; (i)>=(i0);(i)--)
#define SORT(x) sort(x.begin(),x.end())
#define SORTR(x) sort(x.begin(),x.end(),greater<vector<int>>())

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

using namespace std;
using ll = long long;
typedef std::pair<int, int> pii;
typedef std::pair<int, double> pid;
typedef std::vector<int> vi;
typedef std::vector<pii> vii;

#define PI 3.14159265358979323846264338327950L
const int mod = 9999;




void solve(){
    
    ll n,x,m;
    cin >> n >> x >> m;
    
    ll ans = 0;
    ll cur = x;
    
    ll seen[100001] = {};
    ll seenwhere[100001] = {};
    if (x==0){
        cout << 0;
        return;
    }
    
    ll cnt = 0;
    while(n){
        cnt++;
        n--;

        ans += cur;
        cur = ((1LL*cur*cur)%m);
        
        if (seen[cur]){
            ll r = n/(cnt-seenwhere[cur]);
            n %= (cnt-seenwhere[cur]);
            ans += 1LL*r*(ans - seen[cur]);
        }
        seenwhere[cur] = cnt;
        seen[cur] = ans;
    }

    

    
    cout << ans;
}




int main() {
    int T;
    
    T = 1;
    //cin >> T;
    
    while (T--) {
        solve();
        cout << endl;
    }
}


