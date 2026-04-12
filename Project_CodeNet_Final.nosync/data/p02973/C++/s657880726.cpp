#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+2;

int f[N];
void mod(int i, int x){
    i = N-i-1;
    for (; i < N; i |= i+1)
        f[i] = max(f[i], x);
}
int get(int i){
    i = N-i-1;
    int res = 0;
    for (; i >= 0; i = (i&(i+1))-1)
        res = max(res, f[i]);
    return res;
}

int a[N], b[N];
int main(){
    int n; cin >> n;
    for (int i = 0; i < n; ++ i)
        cin >> a[i];

    int idx[n];
    iota(idx, idx+n, 0);
    sort(idx, idx+n, [&](int i, int j){
        return a[i] < a[j];
    });

    for (int i = 0, c = 0; i < n; ++ i){
        if (i && a[idx[i]] != a[idx[i-1]])
            ++ c;
        b[idx[i]] = c;
    }

    for (int i = 0; i < n; ++ i)
        mod(b[i], get(b[i])+1);
    cout << get(0) << endl;
}
