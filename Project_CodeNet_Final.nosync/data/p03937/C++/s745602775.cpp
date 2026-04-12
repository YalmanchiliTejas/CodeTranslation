#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
typedef long long ll;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define rrep(i,n,a) for(int i=n;i>=a;i--)
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(s) s.begin(),s.end()
#define lla(s) s.rbegin(),s.rend()
#define pcnt(b) __builtin_popcount(b)
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const ll INF = 1e18;

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w;
    cin>>h>>w;
    string s[h];
    int c = 0;
    rep(i,0,h){
        cin>>s[i];
        rep(j,0,w){
            if(s[i][j]=='#'){c++;}
        }
    }
    string ans = (c==h+w-1?"Possible":"Impossible");
    cout<<ans<<endl;
}
