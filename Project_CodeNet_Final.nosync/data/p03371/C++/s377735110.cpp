#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vs = vector<string>;
#define  rep(i,n) for(ll i = 0; i < (n); ++i)
#define  red(i,n) for(ll i = (n)-1; i >= 0; --i)
#define  all(a)   begin(a),end(a)
#define  pb(a)    push_back(a)
#define  yn       cout<<"Yes\n"; else cout<<"No\n";
inline ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
const int INF=1000000009;
const ll LINF = 1e18;


int main()
{
    ll a,b,c,A,B,C;
    cin>>a>>b>>c>>A>>B;
    
    if(a+b>c+c){
        C=min(A,B);
        cout<<min(c*max(A,B)*2,c*C*2+max((A-C)*a,(B-C)*b))<<endl;
    }
    else cout<<a*A+b*B<<endl;

    return 0;
}
