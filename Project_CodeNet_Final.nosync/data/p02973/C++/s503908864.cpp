#include <bits/stdc++.h>
using namespace std;

template <class type> class SegmentTree{
public:
    int size;
    vector<type> tree;
    type def;
    type (*marge)(type, type);

    SegmentTree(int n, type d, type (*m)(type, type)){
        size = 1;
        def = d;
        marge = m;
        n++;

        while(size < n){
            size *= 2;
        }

        tree.resize(2*size);

        for(int i = 0;i < size;i++){
            tree[size-1+i] = def;
        }

        for(int i = size-2;i >= 0;i--){
            tree[i] = marge(tree[i*2+1], tree[i*2+2]);
        }

        return;
    }

    SegmentTree(int n, type array[], type d, type (*m)(type, type)){
        size = 1;
        def = d;
        marge = m;
        n++;

        while(size < n){
            size *= 2;
        }

        tree.resize(2*size);

        for(int i = 0;i < size;i++){
            if(i < n) tree[size-1+i] = array[i];
            else tree[size-1+i] = def;
        }

        for(int i = size-2;i >= 0;i--){
            tree[i] = marge(tree[i*2+1], tree[i*2+2]);
        }

        return;
    }

    void update(int i, type val){
        i = size-1+i;
        tree[i] = val;

        while(i > 0){
            i = (i-1)/2;
            tree[i] = marge(tree[i*2+1], tree[i*2+2]);
        }

        return;
    }

    void add(int i, type val){
        i = size-1+i;
        tree[i] = tree[i] + val;

        while(i > 0){
            i = (i-1)/2;
            tree[i] = marge(tree[i*2+1], tree[i*2+2]);
        }

        return;
    }

    type get(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return def;
        if(a <= l && r <= b) return tree[k];

        type vl = get(a, b, 2*k+1, l, (l+r)/2);
        type vr = get(a, b, 2*k+2, (l+r)/2, r);

        return marge(vl, vr);
    }

    type get(int a, int b){
        return get(a, b, 0, 0, size);
    }
};

int marge(int i, int j){
    return max(i, j);
}

int sum(int i, int j){
    return i + j;
}

int main(){
    int n;
    cin >> n;

    int a[100010];
    set<int> st;
    vector<int> vec;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        if(st.find(a[i]) == st.end()){
            vec.push_back(a[i]);
        }
    }

    sort(vec.begin(), vec.end());

    SegmentTree<int> seg(n, -1, marge);
    SegmentTree<int> seg2(n, 0, sum);

    int ans = 0;

    for(int i = 0;i < n;i++){
        int idx = lower_bound(vec.begin(), vec.end(), a[i])-vec.begin();
        int tmp;

        if(idx != 0){
            tmp = seg.get(0, idx);
        }

        if(idx == 0 || tmp == -1){
            ans++;
            seg.update(idx, idx);
            seg2.add(idx, 1);
        }else{
            seg2.add(tmp, -1);
            if(seg2.get(tmp, tmp+1) == 0){
                seg.update(tmp, -1);
            }
            seg.update(idx, idx);
            seg2.add(idx, 1);
        }
    }

    cout << ans << endl;

    return 0;
}
