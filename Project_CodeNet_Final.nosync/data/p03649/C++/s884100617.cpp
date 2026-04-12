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
vector<ll> a,b;

bool can(ll x){
    for(int i=0;i<n;i++){
        b[i]=a[i]+x;
    }
    ll cnt=0;
    for(auto &I:b){
        cnt+=(I+1)/(n+1);
    }
    return cnt<=x;
}


int main(){
    cin>>n;
    a.resize(n);
    b.resize(n);
    ll cnt=0;
    for(auto &I:a){cin>>I; cnt+=I;}
    for(ll i=max(cnt-n*n,0LL);;i++){
        if(can(i)){cout<<i<<endl; return 0;}
    }
    
    
    
    return 0;
}
