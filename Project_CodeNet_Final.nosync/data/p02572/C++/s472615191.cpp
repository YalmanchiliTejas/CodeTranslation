#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <string>
#include <utility>
#include <map> 
#include <queue>
#include <stack>
#include <iomanip>
#include <sstream>
#define MP make_pair
#define PB push_back
#define SZ size()
#define B begin()
#define E end()
#define ll long long
#define REP(i,a,n) for(ll i=a; i<n; ++i)
#define RED(i,n,a) for(ll i=n; i>=a; --i)
#define m9 1000000007
#define endl "\n"
#define F first
#define S second
#define ld long double
#define eps 0.00000000001
#define MAX 1000000007
#define vll vector <ll> 
#define pll pair <ll,ll> 

using namespace std;

ll gcd(ll a, ll b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b, a%b);
    }
}
ll powc(ll a, ll b){
    if(b<0){
        return -1;
    }
    ll res=1;
    while(b>0){
        if(b&1){
            res*=a;
        }
        a*=a;
        //res%=m9, a%=m9;
        b>>=1;
    }
    return res;
}



///target expert

int main(){
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin>>n;
    vector <ll> v(n), suf(n-1);
    REP(i,0,n){
        cin>>v[i];
    }
    ll ans=0;
    suf[n-2]=v[n-1]%MAX;
    RED(i,n-3,0){
        suf[i]=suf[i+1];
        suf[i]+=v[i+1];
        suf[i]%=MAX;
    }
    REP(i,0,n-1){
        //cout<<v[i]<<" "<<suf[i]<<endl;
        ans+=((v[i]%MAX)*(suf[i]%MAX))%MAX;
        ans%=MAX;
    }
    cout<<ans;
}

