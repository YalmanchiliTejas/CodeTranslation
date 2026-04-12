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

ll nums[59];
ll tmp[59];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin>>N;
    
    rep(i,N) cin>>nums[i];
    
    ll total=0;
    bool f=true;
    while(f){
        mem(tmp,0);
        ll cnt=0;
        rep(i,N)if(nums[i]>=N){
            tmp[i]=nums[i]/N;
            cnt+=tmp[i];
            nums[i]%=N;
        }
        f=false;
        rep(i,N){
            nums[i]+=cnt-tmp[i];
            if(nums[i]>=N) f=true;
        }
        total+=cnt;
    }
    cout1(total)
}