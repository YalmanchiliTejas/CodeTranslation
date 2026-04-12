#include <bits/stdc++.h> //全てのヘッダファイルをインクルード

//ループ
#define rep(i, n) for(int i = 0; i < n; i++) //普通のループ
#define repr(i, n) for(int i = n; i >= 0; i--) //逆ループ

//型名省略
typedef long long ll;
//値
static const ll MX = 100005;
static const ll MX_ll = 1e18;

using namespace std;

//#include "./lib/generic/search.h"

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    ll ans=0, sum=0;
    rep(i,n){
        cin >> a[i];
        if(i>=1){
            sum+=a[i];
        }
    }
    for(int i=0; i<n-1; i++){
        ans+=((sum%1000000007)*(a[i]%1000000007))%1000000007;
        if(ans>=1000000007) ans=ans%1000000007;
        sum-=a[i+1];
    }
    ans=ans%1000000007;
    cout << ans << endl;
    return 0;
}
