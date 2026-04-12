#include<bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T,class U> inline bool chmin(T&x,U y){if(x>y){x=y;return true;}return false;}
template<class T,class U> inline bool chmax(T&x,U y){if(x<y){x=y;return true;}return false;}
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int x;
    cin>>x;
    puts(x<30?"No":"Yes");
}