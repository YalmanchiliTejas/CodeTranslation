#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "  = " << x << endl
typedef long long int ll;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

#define dbg2(x, y)                                                       \
    {                                                                    \
        cout << #x << ": " << (x) << " , " << #y << ": " << (y) << endl; \
    }
#define fo(i, n) for (int i = 0; i < n; i++)
#define fok(i, k, n) for (int i = k; i < n; i++)
#define foA(i, A) for (auto i : A)
const int mxN=101;
const int modd=1e9+7;


int main(){
    int n;
    cin>>n;
    ll a[n];
    fo(i, n)cin>>a[i];
    ll dp[n+1][n+1]={0};
    /*
    fo(i, n)dp[i][i]=a[i];
    fo(i, n){
        fok(j,i+1, n){
            dp[i][j]=max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]);
        }
    }*/
    for(int ws=1;ws<=n;ws++){
        for(int i=0;i<n-ws+1;i++){
            int j=i+ws-1;
            if(i==j)dp[i][j]=a[i];
            else{
                dp[i][j]=max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]);
            }
        }
    }
    ll ans=dp[0][n-1];
    cout<<ans;
}