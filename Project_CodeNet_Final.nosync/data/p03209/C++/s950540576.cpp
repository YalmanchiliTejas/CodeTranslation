#include "bits/stdc++.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define FOR(i,init,a) for(int i=init; i<a; i++)
#define rep(i,a) FOR(i,0,a)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()
#define chmin(a,b) a=min(a,b);
#define chmax(a,b) a=max(a,b);

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

ll N,X;
ll allNum[59];
ll pNum[59];
ll bNum[59];

ll dfs(int depth, ll num){
    if(num<=0) return 0;
    if(allNum[depth]<=num) return pNum[depth];
    ll res=0;
    num--;
    if(num>=allNum[depth-1]){
        res += pNum[depth-1];
        num -= allNum[depth-1];
        if(num>0) num--, res++;
    }
    res += dfs(depth-1,num);
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>X;
    
    allNum[0]=1;
    pNum[0]=1;
    bNum[0]=0;
    rep1(i,50) allNum[i] = allNum[i-1]*2+3;
    rep1(i,50) pNum[i] = pNum[i-1]*2 + 1;
    rep1(i,50) bNum[i] = bNum[i-1]*2 + 2;
    
    ll ans = dfs(N,X);
    cout1(ans)
}