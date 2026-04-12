#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

ll a[55], p[55];

ll f(ll n, ll x){
    if(n == 0){
        return ((x <= 0) ? 0 : 1);
    }else if(x <= 1 + a[n-1]){
        return f(n-1, x-1);
    }else{
        return p[n-1]+1 + f(n-1, x-a[n-1]-2);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll N, X;
    cin >> N >> X;

    a[0] = 1;
    p[0] = 1;
    for (int i = 1; i <= N; ++i) {
        a[i] = a[i-1] * 2 + 3;
    }

    for (int i = 1; i <= N; ++i) {
        p[i] = p[i-1] * 2 + 1;
    }

    cout << f(N, X) << "\n";

    return 0;
}
