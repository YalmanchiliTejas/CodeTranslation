#include <bits/stdc++.h>
using namespace std;
#define int long long
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using P=pair<long long,long long>;
#define rep(i,n) for(long long i=0; i<(long long)n; i++)
#define FOR(i,a,b) for(long long i=a; i<b; i++)
#define ll long long
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((long long)(x).size())
#define COUT(x) cout << x << endl
#define PB(x) push_back(x)
#define MP make_pair
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstr vector<string>
#define SUM(x) accumulate(x.begin(),x.end(),0)
#define MAX(x) max_element(x.begin(),x.end())
#define MIN(x) min_element(x.begin(),x.end())
#define couty cout<<'Y'<<'e'<<'s'<<endl
#define coutn cout<<'N'<<'o'<<endl
#define coutY cout<<'Y'<<'E'<<'S'<<endl
#define coutN cout<<'N'<<'O'<<endl
#define yn(x) cout<<(x?"Yes":"No")<<endl
#define YN(x) cout<<(x?"YES":"NO")<<endl
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
const long long dx[4]={1,0,-1,0};
const long long dy[4]={0,1,0,-1};
const long long INF = 1e12;
const long long MOD = 1e9+7;
//fixed<<setprecision(15);

signed main(){
    int n,m; cin >> n>> m;
    vvint g(n,vint(n,0));
    rep(i,m){
        int a,b; cin >> a >> b; a--; b--;
        g[a][b]=1;
        g[b][a]=1;
    }
    vint order(n);
    rep(i,n) order[i]=i;

    int res=0;
    do{
        if(order[0]!=0) break;
        bool can=true;
        rep(i,n-1){
            if(g[order[i]][order[i+1]]!=1) can=false;
        }
        if(can) res++;
    }while(next_permutation(all(order)));
    COUT(res);
}