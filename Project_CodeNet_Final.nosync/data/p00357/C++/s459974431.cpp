#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N;
int d[333333];

bool f(){
    int r=0;
    rep(i,N){
        if(i*10>r)return false;
        chmax(r,i*10+d[i]);
    }
    return true;
}

signed main(){
    cin>>N;
    rep(i,N)cin>>d[i];

    bool ok=true;
    ok&=f();
    reverse(d,d+N);
    ok&=f();
    if(ok)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}