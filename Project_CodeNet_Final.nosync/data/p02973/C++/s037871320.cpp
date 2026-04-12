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
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define irep(i) for(lint i = 0;; i++)
#define irep1(i) for(lint i = 1;; i++)
#define irep2(i) for(lint i = 2;; i++)
#define rrep(i, n) for(lint i = (lint)(n-1); i >-1; i--)
#define rrepi(i,a,b) for(lint i = (lint)(b-1); i >a-1; i--)
#define repi(i,a,b) for(lint i=lint(a);i<lint(b);i++)
#define rep2(i,a,b,c) for(lint i=lint(a);i>lint(b);i+=c)
#define all(x) (x).begin(),(x).end()
#define sl(c) (('a')<=(c)&&(c)<=('z'))
#define ll(c) (('A')<=(c)&&(c)<=('Z'))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define PI 3.141592653589793
#define cout (cout<<fixed<<setprecision(15))
#define makeupper(t) (transform(all(t),t.begin(),::toupper))
#define makelower(t) (transform(all(t),t.begin(),::tolower))
#define dist(x1,y1,x2,y2) (pow(pow(x2-x1,2)+pow(y2-y1,2),0.5))
#define NEXT_LINE string junk; getline(cin, junk);
#define output(v) do{rep(i,v.size())cout<<(i?" ":"")<<v[i];cout<<"\n";}while(0)
#define output2(v) rep(i,v.size()){rep(j,v[i].size()){cout<<(j?" ":"")<<v[i][j];}cout<<"\n";}
#define INF 1LL<<40
#define IINF 1<<30
#define LINF 9223372036854775807
#define MOD 1000000007
vector<lint> dx={-1,1,0,0,1,1,-1,-1};
vector<lint> dy={0,0,-1,1,1,-1,1,-1};
vector<lint> operator+(const vector<lint>& v1,const vector<lint>& v2){
    vector<lint> v(v1.size()+v2.size(),0);
    rep(i,v1.size())v[i]=v1[i];
    rep(i,v2.size())v[i+v1.size()]=v2[i];
    return v;
}
inline lint sum(vector<lint> v){
    lint sum=0;
    rep(i,v.size())sum+=v[i];
    return sum;
}
inline string replace(string str, string before, std::string after) {
	string::size_type  Pos(str.find(before));
	while (Pos != std::string::npos) {
		str.replace(Pos, before.length(), after);
		Pos = str.find(before, Pos + after.length());
	}
	return str;
}
inline vector<string> split(string s, string delim) {
	vector<string> elems;
	s=replace(s, "#", "HASH");
	s=replace(s, delim,"#");
	stringstream ss(s);
	string item;
	while (getline(ss, item, '#')) {
		elems.push_back(replace(item, "HASH", "#"));
	}
	return elems;
}
inline vector<int> cross(vector<int> a, vector<int> b) {
    return { a[1] * b[2] - a[2] * b[1],a[2] * b[0] - a[0] * b[2],a[0] * b[1] - a[1] * b[0] };
}
inline lint GCD(lint a,lint b){return b?GCD(b,a%b):a;}
inline vector<lint> primeList(lint n) {
    vector<bool> p(n+1);
    vector<lint> list;
    repi(i,1, n+1)p[i] = true;
    repi(i,2,sqrt(n)+1) {
        if (p[i]) {
            repi(j,2,n/i+1) {
                p[i*j] = false;
            }
        }
    }
    repi(i, 2, n+1)if (p[i])list.push_back(i);
    return list;
}
inline set<lint> primeSet(lint n) {
    vector<bool> p(n+1);
    set<lint> set;
    repi(i,1, n+1)p[i] = true;
    repi(i,2,sqrt(n)+1) {
        if (p[i]) {
            repi(j,2,n/i+1) {
                p[i*j] = false;
            }
        }
    }
    repi(i, 2, n+1)if (p[i])set.insert(i);
    return set;
}
inline bool isPrime(int num){
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2){
        if (num % i == 0)return false;
    }
    return true;
}
inline lint max(vector<lint> num){
    lint M=num[0];
    rep(i,num.size())M=max(M,num[i]);
    return M;
}
inline lint min(vector<lint> num){
    lint M=num[0];
    rep(i,num.size())M=min(M,num[i]);
    return M;
}
inline cint cmax(vector<cint> num){
    cint M=num[0];
    rep(i,num.size())if(M<num[i])M=num[i];
    return M;
}
inline cint cmin(vector<cint> num){
    cint M=num[0];
    rep(i,num.size())if(M>num[i])M=num[i];
    return M;
}
inline lint signal(lint val){
    if(val==0)return 0;
    else return val/abs(val);
}
struct IVector2{
    lint x,y;
};
bool operator< (const IVector2 &s, const IVector2 &t){
        return s.x==t.x?s.y<t.y:s.x<t.x;
};
bool operator> (const IVector2 &s, const IVector2 &t){
        return s.x==t.x?s.y>t.y:s.x>t.x;
};
struct IVector3{
    lint x,y,z;
};
struct IVector4{
    lint x,y,z,w;
};
template<typename... args>struct dfs{
    public:
    queue<function<void(void)>> que;
    function<void(args...,dfs<args...>&)> func;
    void run(){
        while(!que.empty()){
            que.front()();
            que.pop();
        }
    }
    void push(args... arg){
        que.push(bind(func,arg...,ref(*this)));
    }
    dfs(args... init,function<void(args...,dfs<args...>&)> func):func(func){
        push(init...);
        run();
    }
};
int main(){
    lint n;
    cin>>n;
    vec a(n);
    rep(i,n)cin>>a[i];
    vector<lint> now;
    rep(i,n){
        auto index=lower_bound(now.rbegin(),now.rend(),a[i]);
        if(index==now.rbegin())now.push_back(a[i]);
        else *(index-1)=a[i];
    }
    cout<<now.size();
}