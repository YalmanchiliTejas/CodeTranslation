#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
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
const double PI = acos(-1);
const long double EPS = 1e-9;
using namespace std;
 
 
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int cnt = 1;
    int top = a[0];
    for(int i = 1; i < n; i++){
        if(top <= a[i]){
            cnt++;
            top = a[i];
        }
    }
    cout << cnt;
}
 
int main() {
    barsik;
    int q = 1;
    //cin >> q;
    while(q--) solve();
}
