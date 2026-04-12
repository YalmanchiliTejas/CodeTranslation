#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll dfs(ll X, ll iL, const vector<ll>& nP, const vector<ll>& nB){
    if(X==0) return 0;
    if(iL==0) return 1;

    X--;
    ll res = 0;
    if(X >= nP[iL-1]+nB[iL-1]){
        res += nP[iL-1];
        X -= nP[iL-1]+nB[iL-1];
    }else{
        return res + dfs(X, iL-1, nP, nB);
    }

    if(X==0) return res;
    X--; res++;

    if(X >= nP[iL-1]+nB[iL-1]){
        res += nP[iL-1];
        X -= nP[iL-1]+nB[iL-1];
    }else{
        return res + dfs(X, iL-1, nP, nB);
    }
    X--;

    return res;
}

int main()
{
    ll N, X;
    cin >> N >> X;
    vector<ll> nP(51, 0);
    vector<ll> nB(51, 0);
    nP[0] = 1;
    for(int i=1;i<=50;i++){
        nP[i] = 1 + 2 * nP[i-1];
        nB[i] = 2 + 2 * nB[i-1];
    }
    auto res = dfs(X, N, nP, nB);
    cout<<res<<endl;

    return 0;
}