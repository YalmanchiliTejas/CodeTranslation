#include <bits/stdc++.h>
#include <math.h>
#include <time.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;

int main(){
    ll n ; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);
    ll ans = 0;
    sort(a.begin(),a.end());

    if(n%2==0){
        for(int i=0;i<n;i++){
            if(i<n/2 - 1){
                ans -= 2*a.at(i);
            }else if(i==n/2 -1){
                ans -= a.at(i);
            }else if(i==n/2){
                ans += a.at(i);
            }else{
                ans += 2*a.at(i);
            }
        }
    }else{
        ll ans1=0,ans2=0;
        //pattern1 big/small (e.g. 3/4 n=7)
        for(int i=0;i<n;i++){
            if(i<n/2 - 1){
                ans1 -= 2*a.at(i);
            }else if(i<=n/2){
                ans1 -= a.at(i);
            }else{
                ans1 += 2*a.at(i);
            }
        }
        //pattern2 small/big (e.g. 4/3 n=7)
        for(int i=0;i<n;i++){
            if(i<n/2){
                ans2 -= 2*a.at(i);
            }else if(i<=n/2 + 1){
                ans2 += a.at(i);
            }else{
                ans2 += a.at(i)*2;
            }
        }
        ans = max(ans1,ans2);
    }
    cout << ans << endl;
}