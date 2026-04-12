#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
bool rin[10][10];
int main() {
    int n,m;
    cin >> n >> m;
    vector<int> a(m),b(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        a[i]--,b[i]--;
        rin[a[i]][b[i]] = true;
        rin[b[i]][a[i]] = true;
    }
    vector<int> fac(n);
    for (int i = 0; i < n; ++i) {
        fac[i] = i;
    }
    int ans = 0;
    do{
        if(fac[0] != 0) break;
        bool ok = true;
        for (int i = 0; i < n-1; ++i) {
            int from = fac[i],to = fac[i+1];
            if(!rin[from][to]) ok = false;
        }
        if(ok) ans++;
    }while(next_permutation(fac.begin(),fac.end()));
    cout << ans << endl;
    return 0;
}