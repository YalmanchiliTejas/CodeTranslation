#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <functional>
#include <queue>
//#include <stack>
#include <climits>
#include <map>
#define Rep(i,n) for(int i=0;i<n;i++)
#define For(i,n1,n2) for(int i=n1;i<n2;i++)
#define REP(i,n) for(ll i=0;i<n;i++)
#define FOR(i,n1,n2) for(ll i=n1;i<n2;i++)
#define put(a) cout<<a<<endl;
#define all(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
using namespace std;
typedef long long ll;
//typedef unsigned long long ull;
typedef pair<int, int> P;

ll n,x;
vector<ll> le;
vector<ll> p;
ll f(ll x,ll n){
    if(x==0){
        return 0;
    }else if(n==0){
        return 1;
    }else if(2*x<le[n]){
        return f(x-1,n-1);
    }else{
        return p[n-1]+1+f(x-le[n-1]-2,n-1);
    }
}


int main() {
    cin >> n >> x;
    //vector<ll> le(n+1);
    le.push_back(1);
    Rep(i,n){
        le.push_back(2*le.back()+3);
    }
    p.push_back(1);
    Rep(i,n){
        p.push_back(2*p.back()+1);
    }
    ll res=0;
    res = f(x,n);
    put(res);
    return 0;
}
