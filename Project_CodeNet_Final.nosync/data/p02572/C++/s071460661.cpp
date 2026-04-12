#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <math.h>
#include <queue>
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;

const int mod=1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll sum=0;
    rep(i,n) {
        sum+=a[i];
        sum%=mod;
    }
    ll ans=0;
    rep(i,n) {
        sum-=a[i];
        if(sum<0) sum+=mod;
        ans+=a[i]*sum;
        ans%=mod;
    }
    cout << ans << endl;
}