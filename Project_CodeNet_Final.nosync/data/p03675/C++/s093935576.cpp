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

signed main(){
    int n;
    cin>>n;
    vint a(n);rep(i,n)cin>>a[i];

    deque<int>d;
    rep(i,n){
        if(i&1)d.push_back(a[i]);
        else d.push_front(a[i]);
    }
    if(n%2==0)reverse(all(d));
    rep(i,n){
        if(i)cout<<" ";
        cout<<d[i];
    }cout<<endl;
    return 0;
}
