#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define all(a) begin(a),end(a)
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define sz(x) ((int)x.size())
#define ins insert
#define rep(i,l,u) for(int i=l;i<=u;++i)
#define reb(i,l,u) for(int i=l;i>=u;--i)
using namespace std;
const int maxn=2e5+10;
const int mod=1e9+7;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
main(){
    int x;
    cin>>x;
    if(x>=30)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
