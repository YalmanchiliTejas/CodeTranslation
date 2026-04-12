#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N =pow(10,9)+7;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll tot=0;
    for(int i=0; i<n; i++){
        cin >> a.at(i);
        tot += a.at(i);
    }
    ll ans=0;
    tot%=N;
    for(int i=0; i<n; i++){
        tot -= a.at(i);
        if(tot<0) tot+=N;
        ans = (ans+a.at(i)*tot)%N;
    }
    cout << ans << endl;
}
