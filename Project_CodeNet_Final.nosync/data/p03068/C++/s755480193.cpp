#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define countof(a) (sizeof(a)/sizeof((a)[0]))
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i < (n); i++)
#define all(a) begin(a),end(a)
template<class T> istream& operator >> (istream& s, vector<T>& v)
{ for (T& x: v) { s >> x; } return s;}
template<class T> void cout_v(const vector<T>& c)
{ for (int i = 0; i < c.size(); i++) cout << c[i] << endl; }
template<class T> void cout_h(const vector<T>& c)
{ for (int i = 0; i < c.size(); i++) cout << c[i] << (i==c.size()-1?"\n":" "); }
template<class T> inline bool chmin(T& a, T b) {return a>b?a=b,true:false;}
template<class T> inline bool chmax(T& a, T b) {return a<b?a=b,true:false;}
template<class T> void sort3a(T& a,T& b,T& c) {if (a>b) swap(a,b); if (b>c) swap(b,c); if (a>b) swap(a,b);}
#define SP << " " <<
#define FMT(a) #a<<":"<<a 
#define FMT2(a,b) #a<<":"<<a<<", "<<#b<<":"<<b 
#define FMT3(a,b,c) #a<<":"<<a<<", "<<#b<<":"<<b<<", "<<#c<<":"<<c 
#define FMT4(a,b,c,d) #a<<":"<<a<<", "<<#b<<":"<<b<<", "<<#c<<":"<<c<<", "<<#d<<":"<<d 

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int N; cin >> N;
    string S; cin >>S;
    int K; cin >>K;
    
    rep(i, N) {
        if (S[i] != S[K-1]) S[i] = '*';
    }

    cout << S <<endl;
}
