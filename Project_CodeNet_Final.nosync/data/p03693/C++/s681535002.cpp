#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
#include <math.h>
#include <map>
#define Z class
#define ln cout<<'\n'
#define ll long long
#define rep(i, n) for(int i = 0; i < (n); ++i)
//ASCII a=97, A=65
// int H[N]; rep(i,N) scanf("%d", &H[i]);
// int max_x = *std::max_element(x.begin(), x.end());
// int min_y = *std::min_element(y.begin(), y.end());
using namespace std;
template<class T> inline bool chmax(T& a, T b){ if(a < b) { a=b; return 1; }return 0;}
template<class T> inline bool chmin(T& a, T b){ if(a > b) { a=b; return 1; }return 0;}
template<Z A>void pr(A a){cout<<a;ln;}
template<Z A,Z B>void pr(A a,B b){cout<<a<<' ';pr(b);}
template<Z A,Z B,Z C>void pr(A a,B b,C c){cout<<a<<' ';pr(b,c);}
template<Z A,Z B,Z C,Z D>void pr(A a,B b,C c,D d){cout<<a<<' ';pr(b,c,d);}
template<Z A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}ln;}

int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }
const long long INF = 1LL << 60;

int main(){
    long A,B,C; cin>>A>>B>>C;
    string res;
    if((B*10+C)%4==0) res="YES";
    else res="NO";
    pr(res);
    
}

