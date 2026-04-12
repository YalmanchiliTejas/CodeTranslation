#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i=a; i<n; i++)
#define RREP(i, a, n) for(ll i=n-1; i>=a; i--)
typedef long long ll;
const ll mod =1e9+7;
const ll inf =1e18;
using namespace std;

ll n;
ll h[20];
int main() {
    cin>>n;
    REP(i, 0, n) cin>>h[i];

    ll cnt=1, mx=h[0];
    REP(i, 1, n){
        if(mx<=h[i]){
            mx=h[i];
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}