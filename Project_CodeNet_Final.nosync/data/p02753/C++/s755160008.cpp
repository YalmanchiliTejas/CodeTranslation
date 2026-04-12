#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>

using namespace std;
using ll = long long int;
using vec = vector<int>;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define Sort(a)   sort(a.begin(), a.end())
const int INF = 2147483647;
const ll  MOD = 1000000007;

int main() {
    char bus[3];

    rep(i, 3) {
        cin >> bus[i];
    }

    bool ans = false;

    if(bus[0] == bus[1] && bus[1] == bus[2] && bus[0] == bus[2]) ans = true;

    cout << ((ans)? "No": "Yes");
}