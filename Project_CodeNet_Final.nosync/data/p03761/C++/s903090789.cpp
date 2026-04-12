#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep1(i,n) for(int i=1; i<=(n); ++i)
#define repi(i,a,b) for(int i=a; i<=(b); ++i)
#define rrep(i,n) for(int i=(n-1); i>=0; --i)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define pb push_back
#define mp make_pair
#define to_s to_string
#define sz(v) (int)v.size()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
#define pr(x) cout<<(x)<<'\n'
#define debug(x) cout << #x << ": " << (x) << '\n'
#define yes "Yes"
#define no "No"
using ll = long long;
using namespace std;
typedef pair<int,int> P;
struct aaa{aaa(){ cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);};}aaaaaaa;
int MOD = 1e9 + 7;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int n;
string s,ans;
int main(){
    cin >> n >> s;
    ans = s;
    rep1(i,n-1){
        map<char,int> ini = {};
        map<char,int> input = {};
        cin >> s;
        rep(j,sz(ans)) ini[ans[j]]++;
        rep(j,sz(s)) input[s[j]]++;
        
        string res = "";
        repi(a,'a','z'){
            int x = min(input[a],ini[a]);
            rep(j,x) res += (char)a;
        }
        ans = res;
    }
    sort(ALL(ans));
    pr(ans);
}