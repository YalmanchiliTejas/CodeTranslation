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

signed main(){
    llin(n);
    YN(n==3|n==5|n==7);
}
