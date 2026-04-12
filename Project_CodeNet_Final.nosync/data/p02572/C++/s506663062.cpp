#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define db(m)  cout<<#m<<" = "<<m<<"\n"

#define MAX 200005

const ll mod = 1000000007;

void bang(){
    ll n; cin>>n;
    vector<ll>v(n);
    ll sum = 0;
    for(auto& i : v){
        cin>>i;
        sum += i;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        sum -= v[i];
        ans += (sum % mod * v[i] % mod) % mod;
    }
    cout<<ans%mod<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int q; cin>>q;
    // while(q--)
        bang();

    return 0;
}