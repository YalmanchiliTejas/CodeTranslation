#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep1(i,n) for(int i=1; i<=(n); ++i)
#define repi(i,a,b) for(int i=a; i<=(b); ++i)
#define rrep(i,n) for(int i=(n-1); i>=0; --i)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define pb push_back
#define mp make_pair
#define sz(v) (int)v.size()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using ll = long long;
using namespace std;
typedef pair<int,int> P;
struct aaa{aaa(){ cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);};}aaaaaaa;
int MOD = 1e9 + 7;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int H,W;
int main(){
    cin >> H >> W;
    char fd[H][W];
    rep(i,H) rep(j,W) cin >> fd[i][j];
    rep(i,H){
        bool flag = true;
        rep(j,W) if(fd[i][j] == '#') flag = false;
        if(flag) rep(j,W) fd[i][j] = '0';
    }
    rep(j,W){
        bool flag = true;
        rep(i,H) if(fd[i][j] == '#') flag = false;
        if(flag) rep(i,H) fd[i][j] = '0';
    }
    
    rep(i,H){
        bool flag = false;
        rep(j,W) if(fd[i][j] != '0') cout << fd[i][j], flag = true;
        if(flag) cout << '\n';
    }
}