#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

int main(){
    int h,w;
    cin>>h>>w;
    int x=0;
    rep(i,h){
        string s;
        cin>>s;
        rep(j,w){
            if(s[j]=='#')x++;
        }
    }
    if(x==(h+w-1))cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}