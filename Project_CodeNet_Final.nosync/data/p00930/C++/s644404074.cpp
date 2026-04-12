#include <cstdio>
#include <set>
#include <vector>
#include <climits>
using namespace std;

// Abstract Lazy Segment Tree (テヲツ環スティツアツ。テ」ツδサテヲツアツ偲・ツ個姪ゥツ??・ツサツカテ」ツつサテ」ツつーテ」ツδ。テ」ツδウテ」ツδ暗ヲツ慊ィ)
// Verified: AOJ テ」ツ?ョテ」ツつサテ」ツつーテヲツ慊ィ verify テ・ツ閉湘・ツ?ィテゥツδィ

const int SIZE = 1 << 19;
template<typename T>
struct lazysegtree {
    // テ」ツδ偲」ツδシテ」ツδ嘉」ツ??・ツ債佚、ツスツ催・ツ??
    T node[2*SIZE], lazy[2*SIZE], I;
    bool need_upd[2*SIZE];

    // テ」ツつェテ」ツδ堙」ツδャテ」ツδシテ」ツつキテ」ツδァテ」ツδウ (update, query テ」ツ?ョ 2 テ」ツ?、テ」ツ?古・ツソツ?ィツヲツ?ッツシツ?
    // update function テ」ツ?ッテァツッツ?・ツ崢イテ」ツつ津ヲツ個?・ツョツ堙」ツ?凖」ツつ凝・ツスツ「テ」ツ?ォテ」ツ?療」ツつ暗」ツ??
    // upd_f(X, Y, l, r) -> テァツッツ?・ツ崢イテ」ツ??[l, r) テ」ツ?ァテ」ツ?づ」ツつ凝」ツつ暗」ツ??」ツ?ェテ」ツδ偲」ツδシテ」ツδ?X テ」ツ?ォ Y テ」ツつ津・ツ渉催ヲツ伉?ッツシツ?
    // lazy テ」ツ?ォテ」ツ?、テ」ツ??」ツ?ヲ update テ」ツ?凖」ツつ凝」ツ?ィテ」ツ?催」ツ?ッテァツッツ?・ツ崢イテ」ツつ?1 テ」ツ?ォテ」ツ?療」ツ?ェテ」ツ??」ツ?ィテ」ツδ静」ツつーテ」ツつ甘」ツ?セテ」ツ??
    T (*upd_f)(T, T, int, int), (*qry_f)(T, T);

    // テヲツシツ氾ァツョツ療・ツュツ静」ツ?ィテ・ツ債佚、ツスツ催・ツ?ε」ツつ津」ツつサテ」ツδε」ツδ暗」ツ?療」ツ??・ツ?ィテ」ツ?ヲテ」ツ?ョ node テ」ツ?ィ lazy テ」ツつ津・ツ債佚、ツスツ催・ツ?ε」ツ?ァテ・ツ按敕ヲツ慊淌・ツ個?
    lazysegtree(T (*op1)(T, T, int, int), T (*op2)(T, T), T X, vector<T> vec) {
        upd_f = op1;
        qry_f = op2;
        I = X;
        fill(lazy, lazy+2*SIZE, I);
        fill(node, node+2*SIZE, I);
        fill(need_upd, need_upd+2*SIZE, false);

        // vec テ」ツ?ョテ・ツ?、テ」ツ?ァテ・ツ按敕ヲツ慊淌・ツ個?
        for(size_t i=0; i<vec.size(); i++) {
            node[SIZE-1+i] = vec[i];
        }
        for(int i=SIZE-2; i>=0; i--) {
            node[i] = qry_f(node[2*i+1], node[2*i+2]);
        }
    }

    void lazy_eval(int k, int l, int r) {
        if(!need_upd[k]) return;
        node[k] = upd_f(node[k], lazy[k], l, r);
        if(r - l > 1) {
            lazy[2*k+1] = upd_f(lazy[2*k+1], lazy[k], 0, 1);
            lazy[2*k+2] = upd_f(lazy[2*k+2], lazy[k], 0, 1);
            need_upd[2*k+1] = need_upd[2*k+2] = true;
        }
        lazy[k] = I;
        need_upd[k] = false;
    }

    // テ・ツ債甘ゥツ鳴凝・ツ個コテゥツ鳴?[a, b) テ」ツ?ォテ・ツッツセテ」ツ?療」ツ?ヲテ・ツ?、 val テ」ツつ津・ツ渉催ヲツ伉?」ツ?陛」ツ?崚」ツつ?
    // (upd_f テ」ツつ津ァツ板ィテ」ツ??」ツ?ヲテ・ツ?ヲテァツ青?
    void update(int a, int b, T val, int l=0, int r=SIZE, int k=0) {
        lazy_eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] = upd_f(lazy[k], val, 0, 1);
            need_upd[k] = true;
            lazy_eval(k, l, r);
        }
        else {
            int mid = (l + r) / 2;
            update(a, b, val, l, mid, 2*k+1);
            update(a, b, val, mid, r, 2*k+2);
            node[k] = qry_f(node[2*k+1], node[2*k+2]);
        }
    }

    // テ・ツ債甘ゥツ鳴凝・ツ個コテゥツ鳴?[a, b) テ」ツ?ォテ・ツッツセテ」ツ?療」ツ?ヲテ」ツつッテ」ツつィテ」ツδェテ」ツつ津ヲツ環陛」ツ?津」ツつ?
    // (qry_f テ」ツつ津ァツ板ィテ」ツ??」ツ?ヲテ・ツ?ヲテァツ青?
    T query(int a, int b, int l=0, int r=SIZE, int k=0) {
        lazy_eval(k, l, r);
        if(b <= l || r <= a) return I;
        if(a <= l && r <= b) return node[k];
        int mid = (l + r) / 2;
        T vl = query(a, b, l, mid, 2*k+1);
        T vr = query(a, b, mid, r, 2*k+2);
        return qry_f(vl, vr);
    }
};

int add(int a, int b, int l, int r) {
    if(a == INT_MAX) return b;
    return a + b;
}

int qry(int a, int b) {
    return min(a, b);
}

int main() {
    int N, Q; scanf("%d%d", &N, &Q);

    vector<int> array(N), info(N);
    set<int> open, close;
    for(int i=0; i<N; i++) {
        char c; scanf(" %c", &c);
        if(c == '(') {
            info[i]++;
            open.insert(i);
            array[i]++;
        }
        if(c == ')') {
            close.insert(i);
            array[i]--;
        }
        if(i != 0) array[i] += array[i-1];
    }

    lazysegtree<int> seg(add, qry, INT_MAX, array);
    while(Q--) {
        int q, idx; scanf("%d", &q); q--;
        if(info[q]) {
            // '(' -> ')'
            seg.update(q, N, -2);
            info[q] ^= 1;
            open.erase(q);
            close.insert(q);

            // テ、ツスツ催ァツスツョ idx テ」ツ?ォテ」ツ?づ」ツつ?')' テ」ツつ?'(' テ」ツ?ォ
            idx = *(close.begin());
            seg.update(idx, N, 2);
            info[idx] ^= 1;
            open.insert(idx);
            close.erase(idx);
        }
        else {
            // ')' -> '('
            seg.update(q, N, 2);
            info[q] ^= 1;
            close.erase(q);
            open.insert(q);

            int lb = -1, ub = N;
            while(ub - lb > 1) {
                int mid = (ub + lb) / 2;
                int val = seg.query(mid, N);
                // printf("mid = %d, val = %d\n", mid, val);
                if(val > 1) ub = mid;
                else lb = mid;
            }

            idx = *(open.lower_bound(ub));
            seg.update(idx, N, -2);
            info[idx] ^= 1;
            close.insert(idx);
            open.erase(idx);
        }
        printf("%d\n", idx + 1);
    }
    return 0;
}