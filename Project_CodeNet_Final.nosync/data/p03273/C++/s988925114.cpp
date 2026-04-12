#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    vector<bool> removed_h(h,false);
    vector<bool> removed_w(w,false);
    rep(i,h) {
        string s = a[i];
        bool flag = true;
        rep(j,s.size()) if(s[j] == '#') flag = false;
        if(flag) removed_h[i] = true;
    }
    rep(i,w) {
        bool flag = true;
        rep(j,h) if(a[j][i] == '#') flag = false;
        if(flag) removed_w[i] = true;
    }
    rep(i,h) {
        if(removed_h[i]) continue;
        string s = a[i];
        rep(j,w) if(!removed_w[j]) cout << s[j];
        cout << endl;
    }
}