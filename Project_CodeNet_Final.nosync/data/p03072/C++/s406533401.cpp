#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <map>
#include <cstdlib>
#define INF (1000000007)
#define rep(i,N) for(ll i=0;i<N;i++)
#define rep2(i,j,k) for(ll i=j; i<k;i++)
typedef long long int ll;
using namespace std;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using vs=vector<string>;
using vvs=vector<vector<string>>;

template <typename T>
void print(T v){
    for(size_t i=0;i<v.size();i++){
        cout<<i<<": "<<v[i]<<endl;}
}

template <typename T>
void print2(T v){
    for(size_t i=0;i<v.size();i++){
        cout<<i<<": ";
        for(size_t j=0;j<v[0].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

template <typename T>
T slice(T v,ll left,ll right){
    T ret(0);
    copy(v.begin()+left,v.begin()+right,back_inserter(ret));
    return ret;
}

int main(){
    ll N;
    ll m=0;
    ll ans=0;
    cin>>N;
    vl h(N);
    rep(i,N){
        cin>>h[i];
    }
    
    rep(i,N){
        m=max(m,h[i]);
        if(m<=h[i]){
            ans++;
        }
    }
    
    cout<<ans<<endl;
            

    return 0;
}