#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
using ll = long long;
const ll mod = 1000000007;
const ll INF = 100000000000000000LL;
signed main(){
    int x,y,z;
    cin>>x>>y>>z;
    x-=z;
    y+=z;
    cout<<x/y<<endl;
}