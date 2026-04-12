#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    deque<ll> q;
    rep(i, n) {
        ll a;
        cin >> a;
        int idx = lower_bound(q.begin(), q.end(), a) - q.begin();
        //cout << idx;
        if (idx == 0) {
            q.push_front(a);
        }
        else if (idx >= i) {
            q[q.size()-1] = a; 
        }
        else {
            q[idx-1] = a;
        }
        //cout << v.size() << endl;
    }
    cout << q.size() << endl;
    return 0;
}
