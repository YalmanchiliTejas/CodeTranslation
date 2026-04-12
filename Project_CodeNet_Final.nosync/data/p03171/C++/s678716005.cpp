#include <bits/stdc++.h>
#define ull uint64_t
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mx5 100005
#define mx6 1000005
#define mod 1000000007
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll out[3001][3001] = {}, total = 0;
    
int main() {
    nfs
    int i, j, d, n, a[3001];
    
    cin >> n;
    

    for (i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
        out[i][i] = (n&1) ? a[i] : 0; 
    }
    for (d = 1; d < n; d++) {
        bool fturn = (n-d)&1;
        for (i = 0, j = i + d; i < n-d; i++, j++) {
            if (fturn)
                out[i][j] = max(a[i] + out[i+1][j], a[j] + out[i][j-1]);
            else
                out[i][j] = min(out[i+1][j], out[i][j-1]);
        }
    }
    cout << 2*out[0][n-1] - total;
}