#include<bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T> inline bool chmin(T&x,T y){if(x>y){x=y;return true;}return false;}
template<class T> inline bool chmax(T&x,T y){if(x<y){x=y;return true;}return false;}
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    istream& in(cin);
    ostream& out(cout);
    int n;
    in>>n;
    vector<ll> a(n);
    for(auto&i:a) in>>i;
    if(n&1){
        if(n==3) return cout<<max({a[0],a[1],a[2]})<<endl,0;
        auto c=vector(3,vector(n,-(1ll<<60)));
        c[0][0]=a[0];
        c[1][1]=a[1];
        c[0][2]=a[0]+a[2];
        c[2][2]=a[2];
        c[1][3]=max(a[0]+a[3],a[1]+a[3]);
        for(int i=4;i<n;++i){
            chmax(c[0][i],c[0][i-2]+a[i]);
            chmax(c[1][i],max(c[1][i-2]+a[i],c[0][i-3]+a[i]));
            chmax(c[2][i],max({c[2][i-2],c[1][i-3],c[0][i-4]})+a[i]);
        }
        cout<<max({c[2][n-1],c[1][n-2],c[0][n-3]})<<endl;
    }
    else{
        if(n==2) return cout<<max({a[0],a[1]})<<endl,0;
        auto c=vector(2,vector(n,-(1ll<<60)));
        c[0][0]=a[0];
        c[1][1]=a[1];
        c[0][2]=a[0]+a[2];
        for(int i=3;i<n;++i){
            chmax(c[0][i],c[0][i-2]+a[i]);
            chmax(c[1][i],max(c[1][i-2],c[0][i-3])+a[i]);
        }
        cout<<max({c[1][n-1],c[0][n-2]})<<endl;
    }
}