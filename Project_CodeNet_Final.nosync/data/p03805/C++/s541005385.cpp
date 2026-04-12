#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/numeric/interval.hpp>
#include <boost/numeric/interval/io.hpp>
using namespace::std;
namespace mp = boost::multiprecision;
typedef mp::number<mp::cpp_dec_float<32,int64_t>> cfloat;
typedef mp::cpp_int cint;
typedef long long lint;
typedef long long ll;
typedef long double ldouble;
typedef vector<lint> vec;
typedef vector<vector<lint>> mat;
typedef vector<vector<vector<lint>>> mat3;
typedef vector<double> dvec;
typedef vector<vector<double>> dmat;
typedef vector<vector<vector<double>>> dmat3;
typedef vector<string> svec;
typedef vector<vector<string>> smat;
typedef vector<vector<vector<string>>> smat3;
typedef vector<pair<lint,lint>> pvec;
typedef vector<vector<pair<lint,lint>>> pmat;
typedef vector<vector<vector<pair<lint,lint>>>> pmat3;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define irep(i) for(lint i = 0;; i++)
#define irep1(i) for(lint i = 1;; i++)
#define irep2(i) for(lint i = 2;; i++)
#define rrep(i, n) for(lint i = (lint)(n-1); i >-1; i--)
#define rrepi(i,a,b) for(lint i = (lint)(b-1); i >a-1; i--)
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)
#define rep2(i,a,b,c) for(lint i=lint(a);i>lint(b);i+=c)
#define all(x) (x).begin(),(x).end()
#define PI 3.141592653589793
#define cout (cout<<fixed<<setprecision(15))
#define dist(x1,y1,x2,y2) (pow(pow(x2-x1,2)+pow(y2-y1,2),0.5))
#define out(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"")<<i;f=1;}cout<<"\n";}while(0)
#define out2(v) for(auto i:v)output(i);
#define input(a,n) lint n;cin>>n;vector<lint>a(n);rep(i,n)cin>>a[i];
#define sum(v) accumulate(all(v),0LL)
#define INF (1LL<<60)
#define IINF (1<<30)
#define LINF 9223372036854775807
#define MOD 1000000007
vector<lint> dx={-1,1,0,0,1,1,-1,-1};
vector<lint> dy={0,0,-1,1,1,-1,1,-1};
inline lint gcd(lint a,lint b){return b?gcd(b,a%b):a;}
inline lint lcm(lint a,lint b){return a*b/gcd(a,b);}
lint binary_search(function<bool(lint)> func) {
    lint left = -1;
    lint right =LINF-1;
    while (right - left > 1) {
        lint mid = left + (right - left) / 2;
        if (func(mid)) right = mid;
        else left = mid;
    }
    return right;
}
int main(){
    lint n,m;
    cin>>n>>m;
    vec a(m),b(m);
    mat v(n,vec{});
    rep(i,m)cin>>a[i]>>b[i];
    rep(i,m){
        v[a[i]-1].push_back(b[i]-1);
        v[b[i]-1].push_back(a[i]-1);
    }
    stack<pair<lint,lint>> s;
    s.push({0,1});
    lint cnt=0;
    while(!s.empty()){
        auto d=s.top();
        s.pop();
        if(d.second==(1<<n)-1){
            cnt++;
        }
        else for(lint to:v[d.first]){
            if(!(d.second&(1<<to))){
                s.push({to,d.second+(1<<to)});
            }
        }
    }
    cout<<cnt;
}