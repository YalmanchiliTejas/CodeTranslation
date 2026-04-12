#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

ll calc(vector<PL> a){
    int n = a.size();
    ll mi1 = 1e18, ma1 = 0;
    ll mi2 = 1e18, ma2 = 0;
    REP(i,n){
        mi1 = min(mi1, a[i].first);
        ma1 = max(ma1, a[i].first);
        mi2 = min(mi2, a[i].second);
        ma2 = max(ma2, a[i].second);
    }
    return (ma1 - mi1) * (ma2 - mi2);
}

ll calc2(vector<PL> a){
    int n = a.size();
    ll mi = 1e18, ma = 0;
    REP(i,n){
        mi = min(mi, a[i].first);
        ma = max(ma, a[i].second);
    }
    ll dif = ma - mi;
    sort(ALL(a));
    ll ret = a[n-1].first - a[0].first;
    mi = 1e18, ma = a[n-1].first;
    REP(i,n){
        ma = max(ma, a[i].second);
        mi = min(mi, a[i].second);
        ret = min(ret, ma - min(mi, a[i+1].first));
    }
    return dif * ret;
}

int main() {
    int n;
    cin >> n;
    vector<PL> a(n);
    REP(i,n){
        scanf("%lld %lld", &a[i].first, &a[i].second);
        if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
    }

    cout << min(calc(a), calc2(a)) << endl;

    return 0;
}
