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

vector<ll> b, p;
ll solve(int level, ll x) {
    if(level == 0) {
        return x > 0;
    }
    if(x < b[level - 1] + 2) {
        return solve(level - 1, x - 1);
    } else if(x == b[level - 1] + 2){
        return solve(level - 1, x - 1) + 1;
    } else {
        return p[level - 1] + 1 + solve(level - 1, x - b[level - 1] - 2);
    }
}

signed main(void) {
    int n; ll x; cin >> n >> x;
    
    b.resize(n + 1); p.resize(n + 1);
    b[0] = 1; p[0] = 1;
    rep(i, n) {
        b[i + 1] = b[i] * 2 + 3;
        p[i + 1] = p[i] * 2 + 1;
    }

    cout << solve(n, x) << endl;

    return 0;
}
