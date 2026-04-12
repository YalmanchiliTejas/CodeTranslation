#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/numeric/interval.hpp>
#include <boost/numeric/interval/io.hpp>
#include <boost/any.hpp>
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
#define output(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"")<<i;f=1;}cout<<"\n";}while(0)
#define output2(v) for(auto i:v)output(i);
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
struct SEG{
    lint n=1;
    vec node,lazy;
    SEG(lint size){
        while(n<size)n<<=1;
        n*=2;
        node.resize(2*n-1,0);
        lazy.resize(2*n-1,0);
    }
    //0-indexed [a,b)
    void add(lint a,lint b,lint x,lint k=0,lint l=0,lint r=-1){
        if(r<0)r=n;
        if(a<=l&&r<=b){
            node[k]+=(r-l)*x;
            if(k<n-1){
                lazy[2*k+1]+=x;
                lazy[2*k+2]+=x;
            }
        }else if(l<b&&a<r){
            node[k]+=(min(b,r)-max(a,l))*x;
            add(a,b,x,2*k+1,l,(l+r)/2);
            add(a,b,x,2*k+2,(l+r)/2,r);
        }
    }
    //0-indexed [a,b)
    lint get(lint a,lint b,lint k=0,lint l=0,lint r=-1){
        if(r<0)r=n;
        if(b<=l||r<=a)return 0;
        if(a<=l&&r<=b)return lazy[k]*(r-l)+node[k];
        if(k<n-1){
            lazy[2*k+1]+=lazy[k];
            lazy[2*k+2]+=lazy[k];
        }
        lazy[k]=0;
        return get(a,b,2*k+1,l,(l+r)/2)+get(a,b,2*k+2,(l+r)/2,r);
    }
};
int main(){
    lint n;
    cin>>n;
    cout<<800*n-(n/15)*200;
}
