#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll N, X;

vector<ll> L(55, -1), ACC(55, 0);
vector<ll> r = {0, 1, 2, 3, 3};

ll dfs1(ll i){
    if(i == 1){
        L[i] = 5;
        ACC[i] = 3;
        return 5;
    }
    if(L[i] == -1){
        L[i] = 2 * dfs1(i-1) + 3;
        ACC[i] = 2 * ACC[i-1] + 1;
    }
    return L[i];
}

ll dfs2(ll i, ll t){
    if(i == 1) return r[t];
    if(t == 0) return 0;
    if(t == L[i]-1) return 2 * ACC[i-1] + 1;
    if(t == L[i]/2) return ACC[i-1] + 1;
    if(t < L[i]/2) return dfs2(i - 1, t - 1);
    if(t > L[i]/2) return ACC[i-1] + dfs2(i - 1, t - L[i-1] -  2) + 1;
}

int main(){
    cin >> N >> X;
    dfs1(N);
    cout << dfs2(N, X-1) << endl;
    return 0;
}