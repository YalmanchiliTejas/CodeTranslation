#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR(i,k,n) for(ll i=(k);(k)<(n)?i<(n):i>(n);(k)<(n)?i+=1:i-=1)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int INF = 1<<29;
typedef long long ll;
typedef unsigned long long ull;
typedef vector< ll > vi;
typedef vector< vi > vvi;
typedef pair< ll,ll > ii;
#define F first
#define S second
#define EB emplace_back
#define PB push_back
#define MP make_pair
#define sz(a) ll((a).size())
#define all(o) (o).begin(), (o).end()
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(all(container),element) != container.end())
#define TR(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
template<class T> T** arr2D(int n,int m,T init){
    T** mat=new T*[n];
    FOR(i,0,n){
        mat[i]=new T[m];
        FOR(j,0,m){
            mat[i][j]=init;
        }
    }
    return mat;
}
template<class T> void initialise(T** mat,T init,int n,int m){
    FOR(i,0,n){
        FOR(j,0,m){
            mat[i][j]=init;
        }
    }
}
template<class T> void destroy(T** mat,int n,int m){
    FOR(i,0,n){
        delete[] mat[i];
    }delete[] mat;
}
const int MOD = 1000000007;
ll fastpowMOD(ll a, ll p,ll MOD){ if(p==0) return 1; ll z = fastpowMOD(a,p/2,MOD); z = (z*z)%MOD; if(p%2) z = (z*a)%MOD; return z; }

/////////////////////////////////////////////////////////////////////
ll taro_pts[3000][3000][2];
//0--> taro's move
//1--> Jiro's move
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
void solve(){
    int N;
    cin>>N;
    vector<int> arr(N);
    FOR(i,0,N)cin>>arr[i];
    FOR(len,1,N+1){
        FOR(i,0,N-len+1){
            int j=i+len-1;
            ll ans0,ans1;
            if(len==1){
                ans0=arr[i];
                ans1=0;
            }else{
                ans0=max(taro_pts[i+1][j][1]+arr[i],taro_pts[i][j-1][1]+arr[j]);
                ans1=min(taro_pts[i+1][j][0],taro_pts[i][j-1][0]);
            }
            // debug(i,j,ans0,ans1);
            taro_pts[i][j][0]=ans0;
            taro_pts[i][j][1]=ans1;
        }
    }
    ll x=taro_pts[0][N-1][0];
    ll sum=0;
    FOR(i,0,N)sum+=arr[i];
    ll ans=2*x-sum;
    // debug(sum,ans,x);
    cout<<ans<<'\n';
}
int main()
{
    fastio
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    solve();
    return 0;
}
