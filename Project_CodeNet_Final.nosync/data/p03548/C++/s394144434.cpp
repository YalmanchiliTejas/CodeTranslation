#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;

int main(){
    ll a,b,c; cin >> a >> b >> c;
    ll ans = a/(b+c);
    if(a%(b+c) < c) ans--;
    cout << ans << endl;
}