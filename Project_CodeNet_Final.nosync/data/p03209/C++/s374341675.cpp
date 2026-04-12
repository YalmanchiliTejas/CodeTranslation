#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;
ll N, X;
vector<ll> size, p;

ll rec(ll N, ll X){
    if(N == 0) {
        if(X <= 0) return 0;
        else return 1;
    }
    else if(X <= 1+size[N-1]) return rec(N-1, X-1);
    else return p[N-1] + 1 + rec(N-1, X - 2 - size[N-1]);
    
}


int main(){
    cin >> N >> X;
    size.resize(N+1);
    p.resize(N+1);
    size[0] = 1;
    for(int i = 1; i < N+1; i++) size[i] = 2*size[i-1]+3;
    p[0] = 1;
    for(int i = 1; i < N+1; i++) p[i] = 2*p[i-1]+1;
    cout << rec(N, X) << endl;;


}