/*
1. I'm the Future Red Coder :)
2. Hopefully, I'll be Yellow Soon.
*/
#include<bits/stdc++.h>
#define mod 1000000007
#define lim 1000000000000000007
#define lim1 18446744073709551615  //Unsigned
#define sq(a) ((a)*(a))
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define mms(v,i) memset(v,i,sizeof(v))
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define REPN(i,a,b) for (int i = a; i >= b; i--)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> pi;
typedef pair<ll,ll> PL;
typedef pair<ll,int> PLI;
typedef pair<int,ll> PIL;
typedef pair<int,pair<int,int> > pii;
ll power(ll a,ll b,ll m=mod) {
    if (b==0) return 1;
    ll c = power(a,b>>1,m);
    c = (c*c)%m;
    if (b&1) return (c*a)%m;
    return c;
}
ll gcdll(ll a,ll b) {
    if (b==0) return a;
    return gcdll(b,a%b);
}
int gcd(int a,int b) {
    if (b==0) return a;
    return gcd(b,a%b);
}
/*struct node {
    int l,r,nq;
};
bool compare(const node& a,const node& b) {
    if (a.r != b.r) return a.r<b.r;
    return a.l<b.l;
}*/
/* ******* DSU START ****** */
/*
const int dsusize = (int)1e5+5;
struct node {
    int data;
    int rk,pn;
}dsu[dsusize];
//ll fans;
void initialize(int n) {
    REP(i,1,n) {
        dsu[i].data = 1;
        dsu[i].rk = 0;
        dsu[i].pn = i;
    }
}
int fnd(int i) {
    if (dsu[i].pn != i) dsu[i].pn = fnd(dsu[i].pn);
    return dsu[i].pn;
}
void unn(int i,int j) {
    i = fnd(i);
    j = fnd(j);
    if (i!=j) {
        //fans -= dsu[i].data*dsu[j].data;
        if (dsu[i].rk>dsu[j].rk) {
            dsu[j].pn = i;
            dsu[i].data += dsu[j].data;
        }
        else {
            dsu[i].pn = j;
            dsu[j].data += dsu[i].data;
            if (dsu[i].rk==dsu[j].rk) {
                dsu[j].rk++;
            }
        }
    }
}
*/
/* ******* DSU END****** */

const int N = (int)2e5+5;
const int Q = 250;
multiset<int> s;
int a[N];
void solve() {
    int n;
    cin>>n;
    REP(i,1,n) {
        cin>>a[i];
    }
    s.insert(mod);
    int ans = 0;
    REPN(i,n,1) {
        auto it = s.upper_bound(a[i]);
        if (*it == mod) ans++;
        else s.erase(it);
        s.insert(a[i]);
    }
    cout<<ans;
}
int main() {
    //freopen("class_treasurer.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T=1;
    //cin>>T;
    REP(TC,1,T) {
        //cout<<"Case #"<<TC<<": ";
        solve();
        cout<<"\n";
    }
}
