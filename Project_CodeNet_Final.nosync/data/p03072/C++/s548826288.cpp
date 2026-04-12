#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <list>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)

int main(){
    ll n;
    cin >> n;
    ll h[n];
    rep(i,n) cin >> h[i];
    ll ans=1;
    ll max=h[0];
    for(ll i=1;i<n;i++){
        if(max <= h[i]){
            ans++;
            max=h[i];
        }
    }
    cout << ans << endl;
}