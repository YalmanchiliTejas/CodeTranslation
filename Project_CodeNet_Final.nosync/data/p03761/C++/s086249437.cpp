#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cctype>
#include<climits>
#include<string>
#include<bitset>
#include<cfloat>
#include<iomanip>
#include<numeric>

using namespace std;
using ll =  long long;
using pint =  pair<int,int>;
using vint = vector<int>;
using vvint = vector<vint>;
using vpint = vector<pint>;
#define repi(i,start,end) for(int (i)=(start),TemPNuM=(int)(end);(i)<TemPNuM;++(i))
#define rep(i,end) repi((i),0,(end))
#define rfor(x,v) for(auto& (x) : (v))
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define fsort(v,lambda) sort(all((v)),(lambda))
#define vin(v) rep(i,(v).size())cin >> (v)[i];
#define vpin(v) rep(i,(v).size())cin>>v[i].first>>v[i].second
//#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>void println(T a){if(cout.precision()!=12)cout<<setprecision(12);cout<<a<<endl;}
//lambda: [](int x, int y){return x<y;}

signed main(void) {
    int n; cin >> n;
    vector<map<char, int>> s(n);
    rep(i, n) {
        string t; cin >> t;
        map<char, int> m;
        rfor(c, t) {
            m[c] ++;
        }
        s[i] = m;
    }
    map<char, int> ans;
    for(char c = 'a'; c <= 'z'; ++c) {
        int min = INT_MAX;
        rfor(m, s) {
            chmin(min, m[c]);
        }
        ans[c] = min;
    }
    rfor(p, ans) {
        if(p.second != 0) {
            rep(i, p.second) cout << p.first;
        }
    }
    cout << endl;


    return 0;
}
