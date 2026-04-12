#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll l(ll N){
    if (N==0LL){
        return 1LL;
    }
    return l(N-1)*2LL+3LL;
}
ll P(ll N){
    if (N==0LL){
        return 1LL;
    }
    return P(N-1)*2LL+1LL;
}
ll ans(ll N, ll X){
  	if (X==0LL){
      return 0LL;
    }
    if (N==0LL and X==1LL){
        return 1LL;
    }
    if (X==1LL){
        return 0LL;
    }
    if (X<=l(N-1LL)+1LL){
        return ans(N-1LL,X-1LL);
    }
    if (X==l(N-1LL)+2LL){
        return ans(N-1LL,X-2LL)+1LL;
    }
    if (X<=l(N-1LL)*2LL+2LL){
        return P(N-1LL)+ans(N-1LL,X-l(N-1LL)-2LL)+1LL;
    }
    return P(N);
}
int main()
{
    ll N,X;
    cin >> N >> X;
    cout << ans(N,X) << endl;
    return 0;
}