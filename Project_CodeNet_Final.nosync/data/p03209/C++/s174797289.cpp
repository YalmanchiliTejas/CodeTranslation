#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

ll n,x;
ll c[55],d[55];
void input(){
    cin >> n >> x;
    c[0]=1;
    d[0]=1;
    rep(i,n){
        c[i+1]=2*c[i]+1;
        d[i+1]=2*d[i]+3;
    }
}

ll dfs(ll a, ll b){
    if(a==0 && b>0) return 1;
    if(b<=1) return 0;
    if(b<=1+d[a-1]) return dfs(a-1,b-1);
    if(b==d[a-1]+2) return c[a-1]+1;
    if(b > d[a]) return c[a];
    else return c[a-1]+1+dfs(a-1,b-2-d[a-1]);
}

int main(){
    input();
    ll ans = dfs(n,x);
    cout << ans << endl;
}

