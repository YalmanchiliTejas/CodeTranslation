#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<ll,ll>;
P pan[51];

ll dfs(ll N,ll X){
    if(N==0){
        return 1;
    }
    if(X==0){
        return 0;
    }
    if(pan[N].second == X+1){
        return pan[N].first;
    }
    if(pan[N-1].second+1>X){
        return dfs(N-1,X-1);
    }
    if(pan[N-1].second+1==X){
        return pan[N-1].first+1;
    }
    return pan[N-1].first + 1 + dfs(N-1,X-2-pan[N-1].second);
}

int main() {
    ll N,X;
    cin >> N >> X;
    --X;
    pan[0] = P(1,1);
    for(int i=0;i<N;i++){
        pan[i+1] =P(pan[i].first*2 +1,pan[i].second*2+3); 
    }
    cout << dfs(N,X) << endl;
    return 0;
}