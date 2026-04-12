#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int main(void){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    reverse(h.begin(), h.end());
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        bool flag = true;
        for(int j = i +1; j < n; j++)
        {
            if(h.at(i) < h.at(j)) flag = false;
        }
        if(flag) ans++;
    }
    cout << ans << endl;
    return 0;
}