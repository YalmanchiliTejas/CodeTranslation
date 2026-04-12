#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

ll l[55],p[55];

ll dfs(ll N,ll X){
    if(N==0){
        return ((X<=0)?0:1);
    }else if(X<=1+l[N-1]){
        return dfs(N-1,X-1);
    }else{
        return p[N-1]+1+dfs(N-1,X-l[N-1]-2);
    }
}

int main(){
    ll N,X; cin>>N>>X;
    l[0]=1; p[0]=1;
    for(int i=1;i<=N;++i){
        l[i]=2*l[i-1]+3;
        p[i]=2*p[i-1]+1;
    }

    cout<<dfs(N,X)<<endl;

    return 0;
}

