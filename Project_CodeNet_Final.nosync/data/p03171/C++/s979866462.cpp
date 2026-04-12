#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>
#include<limits.h>
using namespace std;
using T = tuple<int,int,int>;

#define eb emplace_back
#define pb push_back
#define MP make_pair
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i,j,n) for (int i = j; i < n; ++i)
#define repn(i,j,n) for (int i = j; i <= n; ++i)
#define revn(i,j,n) for (int i = j; i >= n; --i)
#define sz(i) i.size()
#define mem(i,v) memset(i,v,sizeof(i))
#define all(v) v.begin(), v.end()
//#define endl '\n'
#define int long long
#define INF 1e7
#define ss second
#define ff first
#define vi vector<int>
#define pri(arr,a,b) repn(i,1,a){repn(j,i+1,b){cout<<arr[i][j]<<" ";}cout<<endl;}

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair<int,pair<int,int>> piii;
 
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int mod=1e9+7;
//const int mod=998244353;
const int up=2e5+10;
const int MAXN=100;

int a[3001],dp[3001][3001];

int solvedp(int i,int j){
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(i==j){
        return dp[i][j]=a[i];
    }
    int ans=max(a[i]-solvedp(i+1,j),a[j]-solvedp(i,j-1));
    return dp[i][j]=ans;
}

void solve()
{
    mem(dp,-1);
    int n;
    cin>>n;
    repn(i,1,n){
        cin>>a[i];
    }
    cout<<solvedp(1,n)<<endl;
}



int32_t main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("inputf.in", "r", stdin);
    //     freopen("outputf.in", "w", stdout);
    // #endif
    fast_cin();
    int T;
    //sieve();
    //Sieve(100);
    //cin>>T;
    T=1;
    int t1=1;
    while(true)
    {  
        solve();  
        t1++;
        if(t1>T)
            break;
    }
}