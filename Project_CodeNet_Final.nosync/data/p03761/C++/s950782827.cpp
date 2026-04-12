#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define pb push_back
#define pf push_front
#define eb emplace_back
using namespace std;
typedef long long ll;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using pi=pair<int,int>;
using vi=vc<int>;
void yes(){ cout << "Yes" << endl; }
void no(){ cout << "No" << endl; }
int SIZE(string s){return (int)s.size();}
const long long INF = 1LL << 60;

int main(){
    cout << fixed << setprecision(20);
    int n; cin >> n;
    vc<ll> ans(26,INF);
    rep(i,n){
        string s; cin >> s;
        map<int,int> m;
        int si = SIZE(s);
        rep(j,si)
            m[s[j]-'a']++;
        rep(j,26) chmin(ans[j], m[j]);
    }
    string ss = "";
    rep(i,26){
        if(ans[i] == INF) continue;
        while(ans[i] > 0){
            ss += 'a'+i;
            ans[i]--;
        }
    }
    cout << ss << endl;
    return 0;
}
