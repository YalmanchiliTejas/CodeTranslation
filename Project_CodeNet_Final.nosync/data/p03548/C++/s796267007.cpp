#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <list>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int ans = 0;
    for(int i = 0; i < 1000000; i++) {
        int a = y*i + z*(i+1);
        if(a <= x) ans = i;
        else break;
    }

    cout << ans << endl;
}
