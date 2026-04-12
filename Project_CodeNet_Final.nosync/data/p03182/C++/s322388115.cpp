#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 25;

int N, M;

vector<pair<int, long long>> end_points[MAXN];

struct SegmentTree {

    int size;
    
    vector<long long> seg;
    vector<long long> lazy;

    SegmentTree(int size) : size(size) {

        seg.resize(size * 10, 0);
        lazy.resize(size * 10, 0);
    }

    void _push_down( int id, int b, int e ) {

        if (lazy[id]) {

            seg[id] += lazy[id];

            lazy[id * 2] += lazy[id];
            lazy[id * 2 + 1] += lazy[id];
            
            lazy[id] = 0LL; 
        }
    }

    void _add( int id, int b, int e, int ib, int ie, long long v) {

        _push_down(id, b, e);

        if (b > ie || e < ib ) {
            return;
        } else if (b >= ib && e <= ie) {
            
            lazy[id] += v;

            _push_down(id, b, e);
            
            return;
        } else {

            _push_down(id, b, e);

            _add(id * 2, b, (b + e) / 2, ib, ie, v);
            _add(id * 2 + 1, (b + e) / 2 + 1, e, ib, ie, v);

            seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
        }
    }

    long long _query( int id, int b, int e, int ib, int ie ) {

        _push_down(id, b, e);

        if ( b > ie || e < ib ) {
            return 0LL;
        } else if (b >= ib && e <= ie ) {
            return seg[id];
        } else {

            long long l = _query(id * 2, b, (b + e) / 2, ib, ie);
            long long r = _query(id * 2 + 1,(b + e) / 2 + 1, e, ib, ie);
            
            return max(l, r);
        }
    }

    long long query( int l, int r) {
        return max(0LL, _query(1, 1, size, l, r));
    }

    long long add(int l, int r, long long v) {
        _add(1, 1, size, l, r, v);   
    }

};

int main() {

    scanf("%d%d", &N, &M);

    SegmentTree segment_tree(N);

    for( int l, r, v, i=1 ; i <= M  ; i++ ) {
        
        scanf("%d%d%d", &l, &r, &v);

        end_points[r].emplace_back(l, v);
    }

    for( int i=1 ; i <= N ; i++ ) {

        long long cur = segment_tree.query(1, max(1, i - 1));

        segment_tree.add(i, i, cur);

        for( auto interval : end_points[i] ) {
            segment_tree.add(interval.first, i, interval.second);
        }
    }

    printf("%lld\n", segment_tree.query(1, N));
    return 0;
}