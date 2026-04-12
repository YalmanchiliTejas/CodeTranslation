#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF=1001001001;
const ll LINF=1001001001001001001;
#define overload4(_1,_2,_3,_4,name,...) name
#define rep1(n) for(ll i=0;i<(n);++i)
#define rep2(i,n) for(ll i=0;i<(n);++i)
#define rep3(i,a,b) for(ll i=(a);i<(b);++i)
#define rep4(i,a,b,c) for(ll i=(a);i<(b);i+=(c))
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define vec vector<ll>
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
const string YES = "Yes";
const string NO = "No";

void solve(ll n, ll m){
    cout<<(n==m?YES:NO)<<endl;
}

int main(){
    ll n;
    scanf("%lld",&n);
    ll m;
    scanf("%lld",&m);
    solve(n, m);
    return 0;
}
