#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <cstring>

#define fi first
#define se second
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = 1; i < (n); ++i)
#define drep(i,n) for (int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define all(x) (x).begin(), (x).end()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define pb push_back
#define sz(x) (int)(x).size()
#define PQ(T) priority_queue<T, v(T), greater<T> >

using namespace std;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int,int>;

const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;

const int mod = 1000000007;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    deque<ll> deq;
    deq.push_front(a[0]);

    for(int i=1; i<n; ++i) {
        if (a[i]<=deq.front()) deq.push_front(a[i]);
        else {
            auto iter = lower_bound(all(deq),a[i]);
            --iter;
            *iter = a[i];
        }
    }
    cout << deq.size() << endl;
    return 0;
}





















