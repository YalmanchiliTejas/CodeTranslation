#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(),v.end()
#define INF 1e9
typedef long long ll;
using namespace std;

int main() {
    int x,y,z; cin >> x >> y >> z;
    cout << (x-z)/(y+z) << endl;
    return 0;
}