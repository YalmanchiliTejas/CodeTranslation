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
#define pr(num) cout << num << endl
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define INF 1000000000000000000
#define MOD 1000000007LL
#define MAX 100010
#define BLACK 0
#define WHITE 1
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;

ll N, X;
ll l[60], b[60], p[60];


ll f(ll n, ll x) {
    if(n==0) {
        if(x<=0) return 0;
        else return 1;
    }
    
    if(x<=l[n]/2) {
        return f(n-1, x-1);
    }else {
        return f(n-1, x-2-l[n-1])+p[n-1]+1;
    }
    
    
}


int main(void) {
    cin >> N >> X;
    ll i;
    l[0]=1;
    b[0]=0;
    p[0]=1;
    for(i=1; i<=50; i++) {
        l[i]=2*l[i-1]+3;
        b[i]=2*b[i-1]+2;
        p[i]=2*p[i-1]+1;
    }
    
    
    pr(f(N, X));
}

