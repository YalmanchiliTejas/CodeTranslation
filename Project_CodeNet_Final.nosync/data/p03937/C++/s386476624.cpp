#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(a,b) for(int a=0;a<(b);++a)
#define REP1(i,n) for(int i=1;i<=(n);++i)
#define debug(x) cerr<<#x<<": "<<x<<'\n'
#define all(x) (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define isYes(x) printf("%s\n",(x) ? "Yes" : "No")
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
//#define INF (1<<29)

const long long INF = 1LL<<60;

#define Sp(p) cout<<setprecision(25)<< fixed<<p<<endl
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define X first
#define Y second
#define pie 3.14159265358979323846
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
template<class T=int>
T in(){T x;cin>>x;return (x);}
template<class T>
void print(T& x){cout<<x<<'\n';}

const int MOD =(int)1e9+7;
const int mod =(int)1e9+7;
const int MAX =510000;
ll fac[MAX],finv[MAX],inv[MAX];
void COMint(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
ll COM(int n,int k){
    if(n<k) return 0;
    if(n<0||k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}
ll gcd(ll a,ll b){
    if(b==0)return a;
    if(a>b){
        swap(a,b);
    }
    return gcd(a,b%a);
}
ll lcm(ll a,ll b){
    ll g;g=gcd(a,b);
    return a*b/g;
}
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

bool compare_by_a(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }
}
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

ll RS(ll N,ll P,ll M){
    if(P==0){
        return 1;
    }else{
        if(P%2==0){
            ll t=RS(N,P/2,M);
            return t*t%M;
        }else{
            return N*RS(N,P-1,M)%M;
        }
    }
}
bool greater_pair(pair<ll,ll> a,pair<ll,ll> b){
    if(a.first!=b.first){
        return a.first>b.first;
    }else{
        return a.second>b.second;
    }
}
ll N,M,Q;
vector<string>A;
void dfs(ll i,ll j,string S){
    if(i==N){
        A.pb(S);
        return;
    }
    for(int k=j;k<M;k++){
        string Snew=S+to_string(k);
        dfs(i+1,k,Snew);
    }
}

string ans="A";
string func(string S){
    if(S.length()<1){
        return "";
    }else{
        return S.substr(1);
    }    
}
const int N_max=100100;

vector<int>dp(N_max,-1);
vector<vector<int>>path(N_max);

int saiki(int v){
    if(dp[v]!=-1){
        return dp[v];
    }else{
        int res=0;
        REP(i,path[v].size()){
            chmax(res,saiki(path[v][i])+1);
        }

        return dp[v]=res;
    }
}
int main() {
    ios::sync_with_stdio(false);
    int H,W;
    cin>>H>>W;
    vector<string>A(H);
    REP(i,H)cin>>A[i];
    vector<pair<int,int>> p(H);
    REP(i,H){
        int flg = 0;
        int s,g;
        s=W;g=W-1;
        REP(j,W){
            if(flg==0&&A[i][j]=='#'){
                flg=1;
                s=j;   
            }else if(flg==1&&A[i][j]=='.'){
                flg=-1;
                g=j-1;
            }else if(flg==-1&&A[i][j]=='#'){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
        p[i]=mp(s,g);
    }

    // REP(i,H){
    //     cout<<p[i].first<<" "<<p[i].second<<endl;
    // }

    REP1(i,H-1){
        if(p[i-1].second>p[i].first){
            // debug(i);
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    cout<<"Possible"<<endl;
    return 0;
}