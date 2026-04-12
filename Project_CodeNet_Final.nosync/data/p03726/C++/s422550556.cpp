#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;

ll n;
vector<vector<ll>> edge;

vector<ll> color;
bool j=false;


ll dfs(ll w,ll p){
    ll cntw=0,cntb=0;
    for(auto &I:edge[w]){
        if(I==p){continue;}
        ll ret=dfs(I,w);
        if(ret==1){cntb++;}
        else{cntw++;}
    }
    if(cntw+cntb==0){return color[w]=0;}
    if(p==-1 && cntw==0){j=true; return color[w]=1;}
    if(cntw==0){return color[w]=0;}
    if(cntw>=2){j=true; return color[w]=1;}
    return color[w]=1;
}



int main(){
    cin>>n;
    edge.resize(n);
    color.resize(n,-1);
    for(int i=1;i<n;i++){
        ll a,b;
        cin>>a>>b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    ll mx=0;
    for(auto &I:edge){mx=max(mx,(ll)I.size());}
    if(mx<=2){cout<<(n&1?"First":"Second")<<endl; return 0;}
    for(int i=0;i<n;i++){
        if(edge[i].size()>=3){dfs(i,-1); break;}
    }
    cout<<(j?"First":"Second")<<endl;
    
    
    return 0;
}
