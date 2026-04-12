#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int64_t> xs, ys, idx;
    cin >> n;
    xs.reserve(n);
    ys.reserve(n);
    idx.resize(n);

    for(int i=0;i<n;++i){
        int x, y;
        cin >> x >> y;
        xs.emplace_back(min(x, y));
        ys.emplace_back(max(x, y));
    }
    
    int64_t rs = INT64_MAX, rb = 0, bs = INT64_MAX, bb = 0;
    int64_t ans;
    for(int i=0;i<n;++i){
        rs = min(rs, xs[i]);
        rb = max(rb, xs[i]);
        bs = min(bs, ys[i]);
        bb = max(bb, ys[i]);
    }
    ans = (rb-rs) * (bb-bs);

    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](auto x, auto y){ return make_pair(ys[x], xs[x]) > make_pair(ys[y], xs[y]); });

    int64_t cs = ys[idx[n-1]], cb = ys[idx[0]], xb = 0;
    int64_t rr = ys[idx[0]] - *min_element(xs.begin(), xs.end());
    
    for(int i=0;i+1<n;++i){
        xb = max(xb, xs[idx[i]]);
        cb = max(xb, ys[idx[i+1]]);
        cs = min(cs, xs[idx[i]]);
        ans = min(ans, rr * (cb-cs));
    }

    cout << ans << endl;

    return 0;
}