#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;
ll dp[0][0];

int main()
{
ll n;
cin >> n;
int table[n]={};
rep(i,n) {
    cin >> table[i];
}
ll max=table[0];
rep(i,n-1){
    if(max<=table[i+1]){
        ans++;
        max=table[i+1];
    }
}

ans+=1;
cout << ans << endl;
return 0;
}



