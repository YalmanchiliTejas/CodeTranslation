#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

#define REP(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    // cout << fixed << setprecision(20);
    int n;cin >> n;
    vector<ll> s(n);
    REP(i,n)cin >> s[i];
    ll ans = 0;
    for(ll c = 1;c <= n-2;c++){
        vector<bool> used(n,false);
        ll cur = 0;
        for(ll k = 0;(k+1)*c < n-1;k++){
            if(used[(n-1)-k*c] or used[(k*c)])break;
            else{
                cur += s[(n-1)-k*c] + s[k*c];
                if(k*c == (n-1)-k*c)break;
                ans = max(ans,cur);
                used[(n-1)-k*c] = 1;
                used[k*c] = 1;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
