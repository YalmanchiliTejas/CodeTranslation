#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>

typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)

using namespace std;

int main(void) {
    int n, k;
    string s;
    cin >> n >> s >> k;

    char r = s[k-1];
    REP(i, n) {
        if (s[i] != r) cout << "*";
        else cout << s[i];
    }
    cout << endl;

    return 0;
}
