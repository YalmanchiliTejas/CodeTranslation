//怪文書

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll, string>;
using garph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int n;cin>>n;
    vector<vector<int>>num(26,vector<int>(n,0));
    rep(i,0,n){
        string s;cin>>s;
        rep(j,0,s.size())num[s[j]-97][i]++;
    }
    string ans;
    rep(i,0,26){
        int a = *min_element(range(num[i]));
        rep(j,0,a)ans.pb(i+97);
    }
    if(ans.size()!=0)cout<<ans<<nnn;
    else cout<<nnn;
    return 0;
}