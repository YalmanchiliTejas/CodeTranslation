#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;
    vector<ll> input(n);
    vector<ll> pref(n);

    for(int i = 0; i<n; i++){
        cin>>input[i];
        pref[i] = input[i];

        if(i != 0){
            pref[i] += pref[i-1];
            pref[i] %= mod;
        }
    }

    ll ans = 0;

    for(int i = 1; i<n; i++){
        ans += pref[i-1]*input[i];
        ans %= mod;
    }

    cout<<ans<<"\n";

    return 0;
}
