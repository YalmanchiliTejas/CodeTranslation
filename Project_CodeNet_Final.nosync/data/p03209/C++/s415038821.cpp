#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
using namespace::std;
namespace mp = boost::multiprecision;
typedef long long lint;
typedef long double ldouble;
#define rep(i, n) for(lint i = 0; i < (lint)(n); i++)
#define rrep(i, n) for(lint i = (lint)(n-1); i >-1; i--)
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
//#define output(v,s) do{rep(i,v.size())cout<<(i?s:"")<<v[i];cout<<"\n";}while(0)
#define output2(v) rep(i,v.size()){rep(j,v[i].size()){cout<<(j?" ":"")<<v[i][j];}cout<<"\n";}
#define INF 1<<30
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
template<typename T>class Stack{
    vector<T> stack;
    public:
        void push(T num) {
            stack.push_back(num);
        }
        T pop() {
            T num = stack[stack.size() - 1];
            stack.erase(stack.end() - 1);
            return num;
        }
        bool empty(){
            return stack.empty();
        }
};
template<typename T>class Queue{
    deque<T> queue;
    public:
        void push(T num) {
            queue.push_front(num);
        }
		void push_back(T num){
			queue.push_back(num);
		}
        T pop() {
            T num = queue[queue.size()-1];
            queue.pop_back();
            return num;
        }
        bool empty(){
            return queue.empty();
        }
};
inline lint signal(lint val){
    if(val==0)return 0;
    else return val/abs(val);
}
inline vector<lint> bit(lint n){
    vector<lint> v(log2(n)+1);
    rep(i,v.size()){
        v[i]=n%2;
        n/=2;
    }
    reverse(all(v));
    return v;
}
inline void bit(lint n,vector<lint>& v){
    rep(i,v.size()){
        v[i]=n%2;
        n/=2;
    }
    reverse(all(v));
}
inline lint btol(vector<lint> bit){
    lint n=0;
    rep(i,bit.size()){
        n=n*2+bit[i];
    }
    return n;
}
lint ans(lint n,lint x){
    if(n==0&&x==1)return 1;
    else if(x==1)return 0;
    else if(x==pow(2,n+1)-1)return pow(2,n);
    else if(x==pow(2,n+2)-3)return pow(2,n+1)-1;
    else if(1<x&&x<pow(2,n+1)-1)return ans(n-1,x-1);
    else if(pow(2,n+1)-1<x&&x<pow(2,n+2)-3)return pow(2,n)+ans(n-1,x-(pow(2,n+1)-1));
    else return -1;
}
int main() {
    lint n,k;
    cin>>n>>k;
    cout<<ans(n,k);
}