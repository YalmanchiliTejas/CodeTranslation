#include <bits/stdc++.h>
#define ll long long
#define int long long
#define vl vector<ll>
#define pl pair<ll,ll>
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,b) for(ll i=0;i<b;i++)
#define per(i,a,b) for(ll i=b-1;i>=a;i--)
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define all(v) (v).begin(),(v).end()
using namespace std;
string s[50];
ll n;
signed main() {
    cin>>n;
    rep(i,n)cin>>s[i];
    rep(j,26) {
        int m = 100;
        rep(i, n)m = min(m, (int) count(begin(s[i]), end(s[i]),(char)j+97));
        rep(i, m) cout <<(char)(j+97);
    }
    cout << endl;
}