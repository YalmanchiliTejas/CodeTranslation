#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
template<typename T>
void print(T x) {
    cout << x << endl;
}
int main(void) {
    int n; cin >> n;
    vector<int> h(n);
    int mx = 0;
    int cnt = 0;
    rep(i, n) {
        cin >> h[i];
        mx = max(h[i], mx);
        if(mx<=h[i]) cnt++;
    }
    cout << cnt;
}
