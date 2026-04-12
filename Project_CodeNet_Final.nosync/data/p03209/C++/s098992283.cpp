#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF = 1e9;
const int mod = 1e9+7;

ll sum[55],pat[55];

ll rec(ll n,ll x)
{
    if(x == sum[n]) return pat[n];
    ll ans = 0;
    x--;
    if(x > 0){
        ll y = min(x,sum[n-1]);
        ans += rec(n-1,y);
        x -= y;
    }
    if(x > 0){
        x--;
        ans++;
    }
    if(x > 0){
        ll y = min(x,sum[n-1]);
        ans += rec(n-1,y);
        x -= y;
    }
    
    return ans;
}

int main()
{
    ll n,x;
    cin >> n >> x;
    sum[0] = pat[0] = 1;
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1] * 2 + 3;
        pat[i] = pat[i-1] * 2 + 1;
    }
    cout << rec(n,x) << endl;
    return 0;
}