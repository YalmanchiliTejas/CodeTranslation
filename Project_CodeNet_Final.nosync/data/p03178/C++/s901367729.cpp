#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define repA(i, a, n) for(int  i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define endl '\n'
#define init(n) int n;cin>>n;int a[n];rep(i,n)cin>>a[i];
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long int> vll;
typedef vector<pii> vii;
ll p=1000000007;
const int N=100005;
string s;int d;
ll dp[10000][100][2];
ll fun(int  pos,int rem,int tight){
    if(pos==s.size()){
        if(rem==0)return 1;
        return 0;
    }
    if(dp[pos][rem][tight]!=-1)return dp[pos][rem][tight];
    int till=9;
    if(!tight)till=s[pos]-'0';
    ll res=0;
    for(int i=0;i<=till;i++){
        int newtight=1;
        if(!tight){
            if(i==till)newtight=0;
        }
        int newrem=(i+rem)%d;
        res=res+fun(pos+1,newrem,newtight);
        res%=p;
    }

    dp[pos][rem][tight]=res;
    // cout<<res<<endl;
    return res;
}
int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);   
    // freopen("output.txt", "w", stdout);
    // #endif
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin>>s>>d;
    memset(dp,-1,sizeof(dp));
    cout<<(fun(0,0,0)-1+p)%p;
    return 0;
}