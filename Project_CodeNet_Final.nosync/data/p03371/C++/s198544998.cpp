#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<int,int>;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll i, j, k;
    i = c * max(x, y) * 2;
    j = a * x + b * y;
    k = c * min(x, y) * 2;
    if(x > y){
        k += a * abs(x-y);
    }else{
        k += b * abs(x-y);
    }

    cout << min(i, min(j, k)) << endl;

    return 0;
}
