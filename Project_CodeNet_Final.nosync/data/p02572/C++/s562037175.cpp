#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
using ll=long long;
#define rsort(n) sort((n).begin(),(n).end(),greater<ll>())

using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n-1);
    rep(i,n)cin >> a[i];
    ll sum=0;
    FOR(i,n,1){
        b[i-1]=a[i];
    }
    for(int i=n-2;i>0;--i){
        b[i-1]+=b[i];
        b[i-1]%=1000000007;
    }
    rep(i,n-1){
        sum+=(a[i]*b[i])%1000000007;
        sum%=1000000007;
    }
    cout << sum << endl;
}