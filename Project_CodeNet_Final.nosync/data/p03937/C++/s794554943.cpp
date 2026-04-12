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
    int h,w;
    cin>>h>>w;
    char s[h][w];
    rep(i,h){
        rep(j,w) cin>>s[i][j];
    }
    int right=0,down=0;
    rep(i,h){
        rep(j,w){
            if(i<h-1&&s[i][j]=='#'&&s[i+1][j]=='#') down++;
            if(j<w-1&&s[i][j]=='#'&&s[i][j+1]=='#') right++;
        }
    }
    if(right==w-1&&down==h-1) cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}