#include <bits/stdc++.h>
using namespace std;
template <typename T> using V = vector<T>;
    
int n, l, r;

bool check(int x, const V<int> &A) {
    for(int i = 0; i < n; i++) {
        if(x % A[i]) continue;
        return (i + 1) % 2 == 1;
    }
    return n % 2 == 0;
}

int calc(int right, const V<int> &A) {
    int ret = 0;
    for(int x = 1; x < right; x++) ret += check(x, A);
    return ret;
}

bool solve() {
    cin >> n >> l >> r;
    if(!(n + l + r)) return false;
    r++;
    V<int> A(n);
    for(int &e : A) cin >> e;
    cout << calc(r, A) - calc(l, A) << endl;
    return true;
}

int main() {
    while(solve());
    return 0;
}

