#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
struct SegmentTree {
private:
    int n;
    vector<int> node;
 
public:
    SegmentTree() {
        int sz = 210000;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);
        for(int i=0; i<sz; i++) node[i+n-1] = 0;
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }
 
    void add(int x, int val) {
        x += (n - 1);
        node[x] += val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }
    // hannkaikukann 
    int getmin(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return INF;
        if(a <= l && r <= b) return node[k];
 
        int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};


int main() {
    //cout.precision(10);
    vector<l_l> balls;
    ll N;
    cin >> N;
    ll max_max = 0;
    ll max_min = INF;
    ll min_max = 0;
    ll min_min = INF;
    for(int i = 1; i <= N; i++) {
        ll x, y;
        cin >> x >> y;
        if(x < y) swap(x, y);
        max_max = max(max_max, x);
        max_min = min(max_min, x);
        min_max = max(min_max, y);
        min_min = min(min_min, y);
        balls.push_back({x, i});
        balls.push_back({y, i});
    }
    SegmentTree seg;
    ll ans = (max_max - max_min) * (min_max - min_min);
    sort(balls.begin(), balls.end());
    ll delta = max_max - min_min;
    ll left = 0;
    ll right = 0;//半開区間
    while(right <= 2 * N) {
        if(seg.getmin(1, N + 1) > 0) {
            ans = min(ans, (balls[right - 1].first - balls[left].first) * delta);
            //cout << left << " " << right << " " << balls[right].first << " " <<  balls[left].first << endl;
            seg.add(balls[left].second, -1);
            left++;
            continue;
        }
        seg.add(balls[right].second, 1);
        right++;
    }
    cout << ans << endl;
    return 0;
}
