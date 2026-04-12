#include<bits/stdc++.h>
using namespace std;
/*  Author : Ded Stark
    Moto :  Chai piyo, biscuit khao     */
#define int long long
#define isspeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<bool> vb;
typedef pair<int, int> pi;

#define pb push_back
#define pf push_front
#define sz(v) (int)v.size()
#define fr(i, n) for(int i=0;i<(n);i++)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define tr(c, it) for(auto it = c.begin();it!=c.end();it++)
#define all(v) v.begin(), v.end()
#define mset(m, v) memset(m, v, sizeof(m))
#define debug(a) cerr << #a << ": " << a << ' ';
#define nl cerr<<'\n';
#define pr(v) tr(v, it)cout<<*it<<' ';cout<<'\n';
#define MP make_pair
#define eb emplace_back
#define F first
#define S second
const int M = 1e9 + 7;const double PI = 2.0*acos(0);
const string here = "here\n";const string yes = "YES\n";const string no = "NO\n";
int binpow(int a, int p){int res=1;for(;p;p>>=1ll){if(p&1)res=(1ll*res*a)%M;a=(1ll*a*a)%M;}return res;}
int dp[10010][100][2][2], d;
string L, R;
int DP(int level, int mod, int thi, int tlo){
    if(level==L.size())
        return (mod ? 0ll : 1ll);
    if(dp[level][mod][thi][tlo]!=-1)
        return dp[level][mod][thi][tlo];
    int temp = 0;
    int blo=0,bhi=9;
    if(tlo)
        blo = L[level]-'0';
    if(thi)
        bhi = R[level]-'0';
    for(int i=blo;i<=bhi;++i){
        int ntlo=tlo, nthi=thi;
        if(i>(L[level]-'0'))
            ntlo=0;
        if((R[level]-'0')>i)
            nthi=0;
        temp = (temp + DP(level+1, (mod+i)%d, nthi, ntlo))%M;
    }
    dp[level][mod][thi][tlo]=temp;
    return dp[level][mod][thi][tlo];
}
void precomp(){

}
void solve(){
    int n, m, i, j, k;
    cin >> R;
    cin>>d;
    L="1";
    mset(dp, -1);
    while(L.size() < R.size())
        L+='0';
    reverse(all(L));
    cout<<DP(0, 0, 1, 1);
}
int32_t main(){
    isspeed
    //clock_t BEGIN = clock();
    #ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
    #endif
    precomp();
    int t = 1;
    //cin>>t;while(t--)
        solve();
    //cerr<<((double)(clock() - BEGIN)/CLOCKS_PER_SEC)<<'\n';
    return 0;
}