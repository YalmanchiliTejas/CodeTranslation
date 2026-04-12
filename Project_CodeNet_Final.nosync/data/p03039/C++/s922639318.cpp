#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vvvll = vector<vector<vector<ll>>>;
using vvvvll = vector<vector<vector<vector<ll>>>>;
using pl4 = pair<ll,ll>;
using str = string;
using vpl4 = vector<pair<ll,ll>>;

#define sz size()
#define be begin()
#define en end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define llin(x) ll (x);cin >>(x);
#define stin(x) str (x);cin >>(x);
#define vllin(x,n) vll (x)(n);FOR(i,0,n-1){cin >>(x)[i];}
#define vllin2(a,b,n) vll (a)(n);vll (b)(n);FOR(i,0,n-1){cin >>(a)[i]>>(b)[i];}
#define vllin3(a,b,c,n) vll (a)(n);vll (b)(n);vll (c)(n);FOR(i,0,n-1){cin >>(a)[i]>>(b)[i]>>(c)[i];}
#define vlling(x,n) (x).assign(n,0);FOR(i,0,n-1){cin >>(x)[i];}
#define vlling2(a,b,n) (a).assign(n,0);(b).assign(n,0);FOR(i,0,n-1){cin >>(a)[i]>>(b)[i];}
#define vlling3(a,b,c,n) (a).assign(n,0);(b).assign(n,0);(c).assign(n,0);FOR(i,0,n-1){cin >>(a)[i]>>(b)[i]>>(c)[i];}
#define vpl4in(x,n) vpl4 (x)((n),mp(0,0));FOR(i,0,n-1){cin >>x[i].fi>>x[i].se;}
#define FOR(i,a,b) for(ll i = a ; i <= b ; i++)
#define rFOR(i,b,a) for(ll i = a; i >= b ; i--)
#define SORT(x) sort(x.be, x.en)
#define rSORT(x) sort(x.rbegin(), x.rend())
#define say(x) cout<<(x);
#define sal(x) cout<<(x)<<endl;
#define says(x) cout<<(x)<<(' ');
#define sas cout<<(' ');
#define sayR(x) cout<<fixed<<setprecision(10)<<(x);
#define salR(x) cout<<fixed<<setprecision(10)<<(x)<<endl;
#define yn(a) cout <<((a)?"yes":"no")<<endl;
#define Yn(a) cout <<((a)?"Yes":"No")<<endl;
#define YN(a) cout <<((a)?"YES":"NO")<<endl;
#define Imp(a) cout <<((a)?"Possible":"Impossible")<<endl;
#define IMP(a) cout <<((a)?"POSSIBLE":"IMPOSSIBLE")<<endl;
#define pow(a,b) ll(pow(a,b))

ll MOD=1000000007;

signed main(){
        llin(n);
        llin(m);
        llin(k);
        ll nm=n*m-2;
        ll l=1;
        ll t=1;
        FOR(i,1,k-2){
                l=(l*nm)%MOD;
                t=(t*i)%MOD;
                nm--;
        }
        ll nn=MOD-2;
        ll r=1;
        while (nn > 0) {
        if (nn & 1) r =r*t%MOD;
        t=t*t%MOD;
        nn >>= 1;
        }
        l=l*r%MOD;
        ll a=0;
        ll b=0;
        ll p=0;
        FOR(i,1,n-1){
                a=(i*m*m*l)%MOD;
                p=(p+a*(n-i))%MOD;
        }
        FOR(i,1,m-1){
                b=(i*n*n*l)%MOD;
                p=(p+b*(m-i))%MOD;
        }
        sal(p);
}
