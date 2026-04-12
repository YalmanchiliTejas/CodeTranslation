#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << "::" << x << endl;
#define debug2(x, y) cout << #x << "::" << x << " " << #y << "::" << y << endl;
#define debug3(x, y, z) cout << #x << "::" << x << " " << #y << "::" << y <<" "<< #z << "::" << z << endl;

#define For(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
const ll mod = 1e9 + 7;
const int MAX = 5 * 1e3 + 5;
typedef pair<int, int> pii;

void add(ll &a, ll b)
{
    a = (a + b) % mod;
    if (a < 0) a += mod;
}

int main() {

    int n;
    cin>>n;
    vector<int> a(n);
    For(i,0,n) cin>>a[i];

    vector<vector<ll>> dp(n,vector<ll>(n));

    for(int l=n-1;l>=0;l--){
        for(int r=l;r<n;r++){
            if(l == r) dp[l][r] = a[l];
            else dp[l][r] = max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
        }
    }

    cout<<dp[0][n-1]<<endl;

    return 0;

}