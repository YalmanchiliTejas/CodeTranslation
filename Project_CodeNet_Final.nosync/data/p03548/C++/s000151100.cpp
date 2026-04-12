#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

typedef long long ll;
#define pb push_back

#define rep(i, n) for (int i=0;i<(n);++i)
#define rep2(i, s, n) for (int i=s;i<(n);++i)
#define rev(i, n) for (int i=(n);i>0;--i)
#define INF (1e9+1e9)

int main() {
    ll x,y,z; cin >> x >> y >> z;

    cout << (x-z)/(y+z) << endl;
    
}