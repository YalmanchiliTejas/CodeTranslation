
#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;
ll MOD=1000000007;

 
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
        vector<vector<ll>> d(n+100,vector<ll>(3,-INF));
        d[0][0]=a[0];
        d[1][1]=a[1];
        d[2][2]=a[2];
        rep(i,n){
            if (i%2==1){
                if (i<n){
                    d[i+2][1]=max(d[i+2][1],d[i][1]+a[i+2]);
                    d[i+3][2]=max(d[i+3][2],d[i][1]+a[i+3]);
                }
            }
            else{
                if (i<n){
                    d[i+2][0]=max(d[i+2][0],d[i][0]+a[i+2]);
                    d[i+3][1]=max(d[i+3][1],d[i][0]+a[i+3]);
                    d[i+4][2]=max(d[i+4][2],d[i][0]+a[i+4]);
                    d[i+2][2]=max(d[i+2][2],d[i][2]+a[i+2]);
                }
            }
        }
        ll ans;
        if (n%2==1){
        ans=max(d[n-1][2],d[n-2][1]);
        ans=max(ans,d[n-3][0]);}
        if (n%2==0) cout << max(d[n-1][1],d[n-2][0]) << endl;
        else cout << ans << endl;
}