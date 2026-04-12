#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    
    int ans = 0;
    vector<int> c(n + 1, -1);
    c[0] = 1e9 + 5;
    rep(i, n){
        int p = 0;
        int q = ans + 1;
        while (q - p != 1){
            int r = (p + q) / 2;
            if (c[r] < a[i])
                q = r;
            else p = r;
        }
        if (c[q] == -1) ans++;
        c[q] = a[i];
    }
    cout << ans << endl;
}