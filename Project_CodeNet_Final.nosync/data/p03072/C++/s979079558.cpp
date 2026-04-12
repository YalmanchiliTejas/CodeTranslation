#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    int highest = 0;
    rep(i,n) {
        int h;
        cin >> h;
        if(h >= highest) {
            ans++;
            highest = h;
        }
    }
    cout << ans << endl;
}