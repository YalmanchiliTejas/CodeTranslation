#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define mkp make_pair
#define pr(num) cout << num << "\n"
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define INF 1000000000000000000
#define MOD 1000000007LL
#define MAX 100010
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;

ll N, X;
ll h[55], p[55];

ll rec(ll lv, ll x) {
    if(lv==0) {
        if(x>0) return 1;
        else return 0;
    }
    
    ll res=0;
    
    if(x>h[lv-1]+1) {
        res+=rec(lv-1, x-h[lv-1]-2)+p[lv-1]+1;
    }else {
        res+=rec(lv-1, x-1);
    }
    
    return res;
}

int main(void) {
    cin >> N >> X;
    ll i;

    h[0]=p[0]=1;
    
    for(i=1; i<=N; i++) {
        h[i]=h[i-1]*2+3;
        p[i]=p[i-1]*2+1;
    }
    
    pr(rec(N, X));
    
    
}























