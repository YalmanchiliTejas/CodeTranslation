#include <bits/stdc++.h>
using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define inf 100000000
#define _GLIBCXX_DEBUG
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int main(){
    int h,w;
    cin >>h>>w;
    vector<string> a(h);
    rep(i,h){
        cin >>a[i];
    }
    vector<bool> row(h,false);
    vector<bool> column(h,false);
    rep(i,h){
        rep(j,w){
            if (a[i][j]=='#'){
                row[i]=true;
                column[j]=true;
            }
                }
    }
    rep(i,h){
        if (row[i]){
            rep(j,w){
                if (column[j]){
                    cout <<a[i][j];
                }
            }
            cout<<endl;
        }
    }
    
}