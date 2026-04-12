#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <numeric>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
#define FOR(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define PUSH(n,v) for(int i=0; i<(n); i++) {int j; cin >> j; v.push_back(j);}
#define ALL(v) v.begin(), v.end()
#define print(s) cout << (s) << endl

int main() {
    vector<pair<int,int>> v;
    int p, s;
    while(scanf("%d,%d", &p, &s), p + s) {
        v.push_back(make_pair(s, p));
    }
    sort(v.begin(), v.end(), greater<pair<int,int>>());
    vector<pair<int,int>> w;
    int ord = 0;
    int ordsc = -1;
    REP(i,v.size()) {
        if (v[i].first == ordsc) {
            
        }else {
            ord++;
            ordsc = v[i].first;
        }
        w.push_back(make_pair(v[i].second, ord));
    }
    sort(w.begin(), w.end());
    int k;
    while(cin >> k) {
        cout << w[k-1].second << endl;
    }
    return 0;
}