#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

ll power(int x, unsigned int y){
    ll res = 1;
    while(y > 0){
        if(y & 1) res = res * x;
        y >>= 1;
        x *= x;
    }
    return res;
}


// Check for number of Cases!!
void solve() {
    int num;

    cin >> num;

    ll arr[num];

    for(int i = 0; i < num; i++)
        cin >> arr[i];

    ll ans=0;

    ll suf[num+2];
    
    suf[num]=0;
    
    for(int i = num - 1; i >= 0 ;i--){
        suf[i]=(suf[i+1]+arr[i])%mod;
    }
    
    for(int i = 0; i < num-1; i++){
        ans=(ans+(arr[i]*suf[i+1])%mod)%mod;
    }
    cout<<ans<<"\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }
}