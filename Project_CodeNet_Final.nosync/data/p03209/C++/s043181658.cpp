#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <queue>
#include <set>
#include <cassert>
using namespace std;
using ll = long long;
using plong = pair<ll,ll>;
ll MOD=998244353;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll rec(ll N,ll X){
    if(N==0)return 1;
    if(X==1)return 0;
    ll len = (1LL<<(N+1))-3;
    ll num = (1LL<<N)-1;
    if(X<=len+1){
        return rec(N-1,X-1);
    }else if(X==len+2){
        return 1+num;
    }else if(X<=(len+1)*2){
        return num+1+rec(N-1,X-2-len);
    }else{
        return (num+1)*2-1;
    }

}

int main(){
    ll N,X;
    cin>>N>>X;
    ll res = rec(N,X);
    cout<<res<<endl;
}