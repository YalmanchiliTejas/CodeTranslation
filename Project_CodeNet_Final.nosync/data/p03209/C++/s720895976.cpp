#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=998244353;
const ll INF=2e15;
const double PI=acos(-1);

vector<ll> a(55),p(55);

ll f(ll n,ll x) {
    if (n==0) return 1;
    else if (x<=n) return 0;
    else if (x<=1+a[n-1]) return f(n-1,x-1);
    else if (x==2+a[n-1]) return p[n-1]+1;
    else return p[n-1]+1+f(n-1,x-a[n-1]-2);

}



int main() {
    ios_base::sync_with_stdio(false); 

    ll n,x;
    cin >> n >> x;
    a[0]=1;
    p[0]=1;
    rep(i,n) {
        a[i+1]=2*a[i]+3;
        p[i+1]=2*p[i]+1;
    }
    cout << f(n,x) << endl;
    


    return 0;
}
