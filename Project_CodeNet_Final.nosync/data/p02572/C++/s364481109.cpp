#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main(){
    int n;
    cin >> n;
    
    ll sum = 0, sum2 = 0;
    
    rep(i,n){
        ll a; cin >> a;
        sum += a;
        sum %= MOD;
        sum2 += a*a;
        sum2 %= MOD;
    }
    sum *= sum;
    sum %= MOD;
    sum += MOD-sum2;
    sum %= MOD;
    
    if(sum%2)cout<<(sum+MOD)/2<<endl;
    else cout<<sum/2<<endl;
    return 0;
}