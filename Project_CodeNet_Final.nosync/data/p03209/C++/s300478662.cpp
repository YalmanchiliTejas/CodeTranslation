#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;

typedef pair<ll, ll>P;
map<P, ll>memo;

ll sum(ll N, ll X){
    //if(X==0LL)cout<<N<<" "<<X<<" "<<0<<endl;
    //else if(N==0LL)cout<<N<<" "<<X<<" "<<1<<endl;
    //else if(X==1LL)cout<<N<<" "<<X<<" "<<0<<endl;
    if(memo.count(P(N, X)))return memo[P(N, X)];
    if(X==0LL)return 0LL;
    if(N==0LL)return 1LL;
    if(X==1LL)return 0LL;
    ll lstlen = 1LL;
    for(ll i = 1LL;i<N;i++)lstlen = 3LL + lstlen + lstlen;
    ll tmp = 0LL;
    if(X <= 1LL){
        tmp = 0LL;
    }
    else if(X <= 1LL + lstlen){
        tmp += sum(N - 1LL, X - 1LL);
    }
    else if(X <= 1LL + lstlen + 1LL){
        tmp = sum(N - 1LL, lstlen) + 1LL;
    }
    else if(X <= 1LL + lstlen + 1LL + lstlen){
        tmp = sum(N - 1LL, lstlen) + 1LL + sum(N - 1LL, X - 1LL - lstlen - 1LL);
    }
    else{
        tmp = sum(N - 1LL, lstlen) + 1LL + sum(N - 1LL, lstlen);
    }

    //cout<<N<<" "<<X<<" "<<tmp<<endl;
    memo[P(N, X)] = tmp;
    return tmp;
}

int main(){

    ll N, X;
    cin>>N >> X;
    cout<<sum(N, X)<<endl;

    return 0;
}