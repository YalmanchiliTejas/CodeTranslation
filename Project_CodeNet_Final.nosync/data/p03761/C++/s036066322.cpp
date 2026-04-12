#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
//#define mod 998244353
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int n;
    cin>>n;
    V<map<int,int>> a(n);
    V<string> s(n);
    cinf(n,s);
    map<int,int> mp;
    rep(i,n){
        int m=s[i].size();
        rep(j,m){
            a[i][s[i][j]-'a']++;
        }
    }
    rep(i,26) mp[i]=1000000;
    rep(i,26){
        rep(j,n) chmin(mp[i],a[j][i]);
    }
    string t;
    rep(i,26){
        int x=mp[i];
        while(x--){
            t+=i+'a';
        }
    }
    cout<<t<<endl;
}