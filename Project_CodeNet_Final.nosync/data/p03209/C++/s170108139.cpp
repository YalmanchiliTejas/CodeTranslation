#include "bits/stdc++.h"
 
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pl4 = pair<ll,ll>;
using str = string;

#define sz size()
#define be begin()
#define en end()
#define fi first
#define se second
#define pb push_back

#define llin(x) ll (x);cin >>(x);
#define stin(x) str (x);cin >>(x);
#define FOR(i,a,b) for(ll i = a ; i <= b ; i++)
#define rFOR(i,b,a) for(ll i = a; i >= b ; i--)
#define SORT(x) sort(x.be, x.en)
#define rSORT(x) sort(x.rbegin(), x.rend())
#define say(x) cout<<(x);
#define sal(x) cout<<(x)<<endl;
#define yn(a) cout <<((a)?"yes":"no")<<endl;
#define Yn(a) cout <<((a)?"Yes":"No")<<endl;
#define YN(a) cout <<((a)?"YES":"NO")<<endl;
#define Imp(a) cout <<((a)?"Possible":"Impossible")<<endl;
#define IMP(a) cout <<((a)?"POSSIBLE":"IMPOSSIBLE")<<endl;

vll k(1);
vll b(1);
ll solve(ll n,ll y){
    if(y>=k[n]) return b[n];
    if(y>k[n-1]+2) return b[n-1]+1+solve(n-1,y-k[n-1]-2);
    if(y==k[n-1]+2) return b[n-1]+1;
    if(y>1) return solve(n-1,y-1);
    return 0;
}
signed main(){
    llin(n);
    llin(x);
    k[0]=1;
    b[0]=1;
    FOR(i,1,n){
        k.pb(2*k[i-1]+3);
        b.pb(2*b[i-1]+1);
    }
    sal(solve(n,x));
}
