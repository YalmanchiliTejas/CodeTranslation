#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#define lli long long int
#define ULTRA_INSTINCT ios_base::sync_with_stdio(false); cin.tie(0)
#define fo(i,n) for(int i=0;i<(n);i++)
using namespace std;

lli mod = 1e9+7;

void solve(){

    int n;
    cin>>n;
    lli a[n];
    lli sum = 0;
    fo(i,n){
        cin>>a[i];
        sum += a[i];
        sum %= mod;
    }
    lli ans = 0;
    fo(i,n){
        sum =  (sum - a[i] + 10*mod)%mod;
        ans += ((a[i] *sum) %mod);
        ans %= mod;
    }
    cout<<ans<<endl;


}

int main(){
    ULTRA_INSTINCT;
    int t =1;
    // cin>>t;
    while(t--){
        solve();
    }

    return 0;
}