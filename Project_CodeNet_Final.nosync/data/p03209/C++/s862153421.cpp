#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> layer;
vector<ll> p;

//anは層の長さの数列、bnはパティの量の数列

ll rec(ll N ,ll X){
    if(N == 0) return 1;
    if(X == 1) return 0;
    ll an = (1ll<<(N+1)) - 3;
    ll bn =  (1ll<<(N)) - 1;

    if(X == an + 2) return bn+1; //層と下から数える数の一致
    else if(X <= an + 1) return rec(N-1,X-1); 
    else if(X <= (an+1)*2) return bn + 1 + rec(N-1,X-an-2);
    else return bn*2+1;
}

int main(){
    ll N,X;
    cin>>N>>X;

    ll ans = rec(N,X);

    cout<<ans<<endl;

    return 0;
}