#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = (s); i < (n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vd vector<double>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define vp vector<P>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
template<class S,class T> istream& operator>>(istream &is,pair<S,T> &p) { return is >> p.first >> p.second; }
template<class S,class T> ostream& operator<<(ostream &os,const pair<S,T> &p) { return os<<'{'<<p.first<<","<<p.second<<'}'; }
template<class T> istream& operator>>(istream &is,vector<T> &v) { for(T &t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) { os<<'[';rep(i,v.size())os<<v[i]<<(i==v.size()-1?']':','); return os; }
void Yes(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YES(bool b) { cout << (b ? "YES" : "NO") << endl; }
template<class T> bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    rep(i,2) rep(j,2) {
        vi ans(n,0);
        ans[0] = i;
        ans[1] = j;
        rep2(k,2,n) {
            if(ans[k-1] xor (s[k-1] == 'x')) {
                ans[k] = ans[k-2];
            } else {
                ans[k] = 1-ans[k-2];
            }
        }
        bool ok = true;
        if(ans[0]) {
            if(s[0] == 'o' xor ans[n-1] == ans[1]) ok = false;
        } else {
            if(s[0] == 'x' xor ans[n-1] == ans[1]) ok = false;
        }
        if(ans[n-1]) {
            if(s[n-1] == 'o' xor ans[n-2] == ans[0]) ok = false;
        } else {
            if(s[n-1] == 'x' xor ans[n-2] == ans[0]) ok = false;
        }
        if(ok) {
            rep(k,n) cout << (ans[k] ? 'S' : 'W');
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}