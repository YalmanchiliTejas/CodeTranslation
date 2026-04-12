#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;

int b[200001];

int main() {

    int n;
    cin >> n;
    vector<int> a(n);

    rep(i, n) {
        cin >> a[i];
    }

    int l=0, r=0;
    rep(i, n) {
        if (i%2) {
            b[n-1-r] = a[n-1-i];
            r++;
        }
        else {
            b[l] = a[n-1-i];
            l++;
        }
    }

    rep(i, n) {
        cout << b[i] << ' ';
    }
    cout << endl;



}
