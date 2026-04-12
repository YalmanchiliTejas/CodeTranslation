#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"

using namespace std;

typedef long int li;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pt;

#define fi first
#define se second
#define dump(x) cout << #x << " = " << x << endl
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll n, a[3007], L, R, res, now;
vector<ll> b;

int main () {
    fastIO;
    cin >> n;
    if(n==1) { cin >> L; cout << L; return 0; }
    for(li i = 0; i < n; i ++) cin >> a[i];
    for(li i = 1; i < n; i ++) b.push_back(max(a[i], a[i-1])-min(a[i], a[i-1]));
    now = 2;
    while(b.size()>1) {
        L=0;
        R=now;
        for(li i = 1; i < b.size(); i++) {
            b[i-1] = max(a[L]-b[i], a[R]-b[i-1]);
            L++;
            R++;
            //cout << b[i] << " ";
        }
        b.pop_back();
        now++;
    }
    cout << b.back();
}
