#include <iostream>
#include <vector>
using namespace std;

const int sz = 1 << 18;

long long data[sz << 1], lazy[sz << 1];

void eval(int k) {
    data[k] += lazy[k];
    if(k < sz) {
        lazy[k << 1] += lazy[k];
        lazy[k << 1 | 1] += lazy[k];
    }
    lazy[k] = 0;
}
void add(int a, int b, long long x, int k = 1, int l = 0, int r = sz) {
    eval(k);
    if(b <= l || r <= a) return;
    if(a <= l && r <= b) {
        lazy[k] += x;
        eval(k);
    } else {
        add(a, b, x, k << 1, l, l + r >> 1);
        add(a, b, x, k << 1 | 1, l + r >> 1, r);
        data[k] = max(data[k << 1], data[k << 1 | 1]);
    }
}
long long getmax(int a, int b, int k = 1, int l = 0, int r = sz) {
    if(b <= l || r <= a) return -1LL << 60;
    eval(k);
    if(a <= l && r <= b) return data[k];
    long long vl = getmax(a, b, k << 1, l, l + r >> 1);
    long long vr = getmax(a, b, k << 1 | 1, l + r >> 1, r);
    return max(vl, vr);
}

int N, M;

vector<pair<int, int>> P[200009];

int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int l, r, a;
        cin >> l >> r >> a;
        P[r].push_back(make_pair(l, a));
    }

    for(int i = 1; i <= N; i++) {
        add(i, i + 1, getmax(0, i));
        for(auto p : P[i]) {
            int l = p.first;
            int a = p.second;
            add(l, i + 1, a);
        }
    }

    cout << getmax(0, N + 1) << endl;

    return 0;
}