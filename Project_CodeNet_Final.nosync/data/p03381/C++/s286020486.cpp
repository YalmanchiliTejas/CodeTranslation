#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

template<class T> void vin(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

int main() {
    int N;
    cin >> N;
    vector<P> X(N);
    rep(i, N) {
        cin >> X[i].first;
        X[i].second = i;
    }
    sort(X.begin(), X.end());
    int l = (N-1)/2;
    vector<int> ans(N);
    rep(i, N) {
        int tmp = X[i].second;
        if (i <= l) {
            ans[tmp] = X[l+1].first;
        }
        else {
            ans[tmp] = X[l].first;
        }
    }
    for (int tmp : ans) {
        cout << tmp << endl;
    }
    return 0;
}