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
#include <array>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main() {
    int n;
    cin >> n;
    VI p(n);
    REP(i,n) cin >> p[i];

    VI ans;
    while (1){
        bool ok = true;
        REP(i,n) if (p[i] != i) ok = false;
        if (ok) break;

        if (p[0] != 0 && p[0] < p[n-1]){
            ans.push_back(n-1);
            swap(p[0], p[n-1]);
        }else{
            ans.push_back(1);
            VI tmp(p);
            REP(i,n-1) p[i] = tmp[i+1];
            p[n-1] = tmp[0];
        }
    }
    cout << ans.size() << endl;
    for (int x : ans) cout << x << endl;
    
    return 0;
}