#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int cnt = 1;
    int temp = h[0];
    for(int i = 1; i < n; ++i) {
        if(temp <= h[i]){
            temp = h[i];
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}