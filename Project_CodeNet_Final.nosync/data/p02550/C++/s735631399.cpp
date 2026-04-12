#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,X,M;

int main(){
    cin>>N>>X>>M;

    vector<ll> A(M+1,0);
    A[0]=X;
    ll s=1;
    vector<ll> idx(M,-1);
    idx[A[0]]=0;
    ll id=0;
    repn(i,M){
        A[i]=A[i-1]*A[i-1]%M;
        if(idx[A[i]]!=-1){
            id=idx[A[i]];
            break;
        }
        if(A[i]==A[0]){
            break;
        }
        idx[A[i]]=i;
        s++;
    }
    //rep(i,s) cout<<i<<' '<<A[i]<<endl;
    ll sum=0;
    for(int i=id;i<s;i++){
        sum+=A[i];
    }
    //cout<<same<<endl;

    ll ans=0;
    rep(i,min(id,N)) ans+=A[i];
    ans+=(N-id)/(s-id)*sum;
    rep(i,max((ll)0,(N-id)%(s-id))) ans+=A[id+i];

    cout<<ans<<endl;
}