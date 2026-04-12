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
#include <algorithm>
#include <climits>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    vector<string> a;
    REP(i, h) {
        string s;
        cin >> s;
        if(s != string(w, '.')) a.push_back(s);
    }

    vector<bool> is_white(w, true);
    REP(i, a.size())REP(j, a[i].size()) {
        if(a[i][j] == '#') is_white[j] = is_white[j] & false;
    }
    REP(i, a.size()) {
        REP(j, a[i].size()) {
            if(not is_white[j]) cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}
