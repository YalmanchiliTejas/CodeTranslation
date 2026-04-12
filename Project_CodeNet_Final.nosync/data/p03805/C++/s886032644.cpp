#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> r(n,vector<int>(n));
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) r[i][j]=0;
    }
    int a,b;
    for (int i=0;i<m;i++) {
        cin >> a >> b;
        r[a-1][b-1]=1;
        r[b-1][a-1]=1;
    }
    vector<vector<int>> t(n,vector<int>(1<<n));
    t[0][1]=1;
    for (int bit=2;bit<(1<<n);bit++) {
        for (int i=0;i<n;i++) {
            int c=0;
            if (bit & (1<<i)) {
                for (int j=0;j<n;j++) {
                    if (r[i][j]==1 && (bit & (1<<j)) && i!=j) c+=t[j][bit-(1<<i)];
                }
            }
            t[i][bit]=c;
        }    
    }
    ll ans=0;
    for (int i=0;i<n;i++) {
        ans+=t[i][(1<<n)-1];
    }
    cout << ans << endl;
}