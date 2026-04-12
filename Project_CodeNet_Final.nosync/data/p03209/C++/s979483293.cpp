#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <list>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <unordered_map>
#include <string.h>
#include<iomanip>
#include <iterator>
#include <locale>

#define all(a) a.begin(),a.end()
#define VV(T) vector<vector< T > >
#define rep(i,N) for(int i = 0; i <N; i++)
#define repsg(i,s,g) for(int i = s; i <g; i++)
#define name(x) #x
using namespace std;

const int INF = INT_MAX;
const long long INFL = 1LL<<40;
const double PI = atan(1)*4;
const long long MOD = pow(10,9)+7;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

typedef long long ll,LL;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
typedef pair<int,int> pii;
typedef pair<LL, LL> pLL;


// vector入力
template<typename T>
istream& operator >> (istream& is, vector<T>& vec){
    for(T& x: vec) is >> x;
    return is;
}
// vector出力
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec){
    for(int i=0; i<vec.size(); i++){
        os << vec[i] << ( i+1 == vec.size() ? "" : " " );
    }
    return os;
}



ll cnt(ll x, ll dep, vector<ll> &barg, vector<ll> &paty){
    if(dep<=0) return (x<=0)?0:1;
    if(x<=barg[dep-1]+1)return cnt(x-1,dep-1,barg,paty);
    else{
        return paty[dep-1]+1 + cnt(x-2-barg[dep-1],dep-1,barg,paty);
    }
}


int main() {
    ll n,x;cin>>n>>x;
    
    vector<ll> barg(n+1);
    vector<ll> paty(n+1);
    barg[0]=1LL;
    paty[0]=1LL;
    rep(i,n){
        barg[i+1]=barg[i]*2+3;
        paty[i+1]=paty[i]*2+1;
    }
    ll ans = cnt(x,n,barg,paty);

        
    cout<<ans<<endl;

    return 0;
}







