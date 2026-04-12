#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi= vector<vi>;
using vs = vector<string>;
#define  rep(i,n) for(ll i = 0; i < (n); ++i)
#define  red(i,n) for(ll i = (n)-1; i >= 0; --i)
#define  all(a)   begin(a),end(a)
#define  pb(a)    push_back(a)
#define  mp(a,b)  make_pair(a,b)
#define  yn(a)    cout << ( (a)?"Yes\n":"No\n" )
inline ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
ll INF = 1e9+9, LINF = 1e18;


int main()
{   
    int a,b;
    cin>>a>>b;
    char c[a][b];
    rep(i,a)rep(j,b)cin>>c[i][j];
    rep(i,a){
        rep(j,b){
            if(c[i][j]<='#')break;
            if(j==b-1) rep(k,b) c[i][k]='a';
        }
    }
    rep(j,b){
        rep(i,a){
            if(c[i][j]<='#')break;
            if(i==a-1) rep(k,a) c[k][j]='a';
        }
    }

    rep(i,a){
        rep(j,b)if(c[i][j]!='a')cout<<c[i][j];
        cout<<endl;
    }
    
    return 0;
}

