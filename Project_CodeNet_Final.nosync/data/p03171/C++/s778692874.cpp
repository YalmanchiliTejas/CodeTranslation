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
#define fi first
#define se second
#define pt(num) cout << num << "\n"
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define chmax(a, b) (a<b ? a=b : 0)
#define chmin(a, b) (a>b ? a=b : 0)
#define INF 1000000000000000000
#define MOD 1000000007LL
#define MAX 101010
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;

ll N;
ll mem[3030][3030];
ll a[MAX];

ll rec(ll l, ll r, ll turn) {
    if(l==r) return 0;
    if(mem[l][r]!=-1) return mem[l][r];
    
    ll res=0;
    if(turn==0)
        res=max(rec(l+1, r, 1)+a[l], rec(l, r-1, 1)+a[r-1]);
    if(turn==1)
        res=min(rec(l+1, r, 0)-a[l], rec(l, r-1, 0)-a[r-1]);

    return mem[l][r]=res;
}

int main(void) {
    cin >> N;
    ll i;
    
    for(i=0; i<N; i++) cin >> a[i];
    
    memset(mem, -1, sizeof(mem));
    pt(rec(0, N, 0));
    
}

