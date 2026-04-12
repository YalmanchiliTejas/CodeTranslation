#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;

int main(){
    ll n ; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);

    vector<vector<ll>> dp(n,vector<ll>(n,0));

    for(int i=0;i<n-1;i++){
        dp.at(i).at(i+1) = abs(a.at(i)-a.at(i+1));
    }

    for(int j=2;j<n;j++){
        for(int i=0;i<n-j;i++){
            dp.at(i).at(i+j) = max(a.at(i) - dp.at(i+1).at(i+j) , a.at(i+j) - dp.at(i).at(i+j-1));  
        }
    }
    /*
    rep(i,n){
        rep(j,n){
            cout << dp.at(i).at(j) << " ";
        }
        cout << endl;
    } 
    */
   if(n!=1){
        cout << dp.at(0).at(n-1) << endl;
    }else{
        cout << a.at(0) << endl;
    }
}