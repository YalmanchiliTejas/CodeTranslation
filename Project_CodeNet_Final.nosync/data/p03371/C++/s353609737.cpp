#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>

#define barsik ios::sync_with_stdio(false)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

typedef long long ll;
typedef std::vector<int> vi;
typedef std::pair <int, int> pii;
typedef std::unordered_set <int> u_si;

using namespace std;

int a, b, c, x, y;

void solve(){
    cin >> a >> b >> c >> x >> y;
    int money = 0;
    if(a + b > 2 * c){
        money += min(x, y) * 2 * c;
        int mn = min(x, y);
        x -= mn;
        y -= mn;
    }
    if(y > 0){
        money += (b * y < 2 * c * y) ? b * y : 2 * c * y;
    }
    if(x > 0){
        money += (a * x < 2 * c * x) ? a * x : 2 * c * x;
    }
    cout << money;
}

int main(){
    barsik;
    int q = 1;
    //cin >> q;
    while(q--) solve();
}

