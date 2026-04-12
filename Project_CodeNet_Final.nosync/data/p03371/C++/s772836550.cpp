#include<bits/stdc++.h>
using namespace std;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<pair<ll, ll> > vp;
typedef vector<string> vs;
typedef vector<char> vc;
typedef list<ll> lst;
typedef pair<ll, ll> P;
const long long INF = numeric_limits<ll>::max();
const long long MOD = 1000000007;
const long double PI = 3.1415926;
template <class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <class T> T &chmax(T &a, const T &b) { return a = max(a, b); }
 
ll n, m, k, ans = 0, sum = 0, cnt = 0;
string s;
//char c;
 
#define Endl endl
 
/*--------------------template--------------------*/

int main() {
    int A, B, C, X, Y;
    cin>>A>>B>>C>>X>>Y;
    int maxi=max(X,Y);
    ans = INF;
    REP(i, maxi+1){
        ll sum=0;
        sum+=2*C*i;
        if(A*(X-i)>0)sum+=A*(X-i);
        if(B*(Y-i)>0)sum+=B*(Y-i);
        ans=min(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}
