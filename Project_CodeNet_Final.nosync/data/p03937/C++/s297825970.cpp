#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define scan(n,v) v.resize(n); rep(i,n){ cin>>v[i];}
#define lim 1000000007ll
#define Yes(flag) cout<<((flag)? "Yes":"No");
#define YES(flag) cout<<((flag)? "YES":"NO");
#include<bits/stdc++.h>
using ll = long long;
using namespace std;
template<class T>T 
chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<class T>T 
chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template <class T> T 
gcd(T a, T b){if (a < b) {a ^= b;b ^= a;a ^= b;} return b ? gcd(b, a % b) : a;}
template <class T> T 
lcm(T a, T b){return a * b / gcd(a, b);}

// header
int h,w;int cnt=0;
char r;
void input(){
    cin>>h>>w;
    rep(i,h){
        rep(j,w){
            cin>>r;
            if(r=='#')cnt++;
        }
    }
}
void src(){
    cout<<((cnt==(h+w-1))? "Possible":"Impossible" );
}   
int main(int argc,char* argv[]){
    ios::sync_with_stdio(false);
 //   ifstream in( argv[1] ); cin.rdbuf(in.rdbuf());
    input();
    src();    
    return 0;
}