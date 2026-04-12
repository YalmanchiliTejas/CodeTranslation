#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <set>
#include<list>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(),v.end()
#define RALL(v) v.rbegin(),v.rend()
#define check(v) rep(i,v.size()) cout << v[i] << " ";\
cout << endl
#define INF 1e9
typedef long long ll;
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> jamp(n);
    rep(i,n) cin >> jamp[i];
    bool flag1 = false, flag2 = false;

    int now = n - 1;
    for(int i = n-2; i >= 0; i--) {
        if(jamp[i]/10>=now-i) {
            now = i;
        }
    }
    if(now==0) flag1 = true;

    reverse(ALL(jamp));
    now = n - 1;
    for(int i = n-2; i >= 0; i--) {
        if(jamp[i]/10>=now-i) {
            now = i;
        }
    }
    if(now==0) flag2 = true;

    if(flag1 && flag2) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}
