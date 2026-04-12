#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int main(void){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    int ans = 0;
    int max_h = 0;
    for(int i = 0; i < n; i++)
    {
        bool flag = true;
        max_h = max(max_h, h.at(i));
        if(max_h != h.at(i)) flag = false;
        if(flag) ans++;
    }
    cout << ans << endl;
    return 0;
}