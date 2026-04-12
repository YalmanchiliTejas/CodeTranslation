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
#define prin(num) cout << num << endl
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define mp make_pair
#define INF 1000000000000000000
#define MOD 1000000007LL
#define MAX 150005
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;

ll modpow(ll x, ll n) {
    ll res=1;
    while(n>0) {
        if(n&1) res=res*x%MOD;
        x=x*x%MOD;
        n>>=1;
    }
    return res;
}

int main(void) {
    ll x;
    cin >> x;
    if(x==3 || x==5 || x==7) {
        puts("YES");
    }else {
        puts("NO");
    }
    
    
    
    
}