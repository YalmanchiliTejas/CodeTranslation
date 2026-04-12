#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main(){
    int n, cnt=0, mx=0;
    cin >> n;
    vector<int> h(n);
    rep(i, n){
        cin >> h[i];
        if(h[i] >= mx) mx = h[i];
        if(h[i] >= mx) cnt++;
    }
    cout << cnt << endl;
}