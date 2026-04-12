#include<bits/stdc++.h>
 
using namespace std;
 
 
#define mod(cans) cans%10**9+7
#define debug(x) cout << "Debug" << x << "\n"
#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define cin_pl(n,x) rep(i,n){cin>>x[i];}
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define prians(Answer) cout<<Answer<<"\n"
#define TF(X) X==1?cout<<"Yes\n":cout<<"No\n"
#define elcon else{continue;}
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int> > matrix;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef greater<int> gi;
typedef vector<unsigned> vu;


ll gcd(ll x, ll y) { return (y == 0) ? x : gcd(y, x % y); }
bool is_prime(const unsigned n){
    switch(n){
        case 0:
        case 1: return false;
        case 2: return true;
    }
 
 
    for(unsigned i=2;i<n;++i){
        if(n%i == 0) return false;
    }
 
    return true;
}

int main()
{
    int n,m,x;cin>>n>>m;
    n==m?x=1:x=0;
    TF(x);
}