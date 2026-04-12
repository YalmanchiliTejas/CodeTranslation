#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)

ll solve(ll *layer,ll *D,ll N,ll X){
    if(N==0) return 1;
    if(X==1) return 0;
    else if( X<=layer[N-1]+1) return solve(layer,D,N-1,X-1);
    else if (X==layer[N-1]+2) return D[N-1]+1;
    else return D[N-1]+1+solve(layer,D,N-1,min(X-layer[N-1]-2,layer[N-1]));
}

int main(){
    ll N,X;
    cin>>N>>X;
    ll layer[50];
    layer[0]=1;
    rep(i,49) layer[i+1]=2*layer[i]+3;
    ll D[50];
    D[0]=1;
    rep(i,49) D[i+1]=2*D[i]+1;
    cout<<solve(layer,D,N,X)<<endl;
    return 0;
}