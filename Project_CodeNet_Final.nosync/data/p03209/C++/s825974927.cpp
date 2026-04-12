#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,X;
    cin >> N >> X;
    vec<ll> P(N+1,1),L(N+1,1);
    for(int i=1;i<=N;i++){
        P[i] = 2*P[i-1]+1;
        L[i] = 2*L[i-1]+3;
    }

    auto dfs = [&](auto&& self,ll x,int level)->ll{
        if(!level) return 1;
        if(x==1) return 0;
        ll res = x>=(L[level-1]+2);
        if(1<x && x<=L[level-1]+1) res += self(self,x-1,level-1);
        else if(x==L[level-1]+2) res += P[level-1];
        else if(x<=L[level]-1) res += P[level-1]+self(self,x-L[level-1]-2,level-1);
        else res += 2*P[level-1];
        return res;
    };

    cout << dfs(dfs,X,N) << "\n";
}