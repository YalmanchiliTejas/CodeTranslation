#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int n;
vector<ll> a(n+1,1);
ll dfs(int n,ll x,ll num){
    ll ans = 0;
    //printf("%d %lld %lld \n",n,x,num);
    if(n==1) return min(x-1,ll(3));
    if(num/2+1==x) return a[n-1] + 1;
    if(x==1) return 0;
    else if(x == num) return a[n];

    if(num/2+1<x){
        ans += a[n-1] + 1;
        x -= (num/2+1);
        num = num/2-1;
        ans += dfs(n-1,x,num);
    }else{
        num = num/2-1;
        --x;
        ans += dfs(n-1,x,num);
    }

    return ans;
}
int main(){
    ll x;
    cin >> n >> x;
    rep(i,n) a[i+1] = a[i]*2 + 1;
    ll num = 4;
    rep(i,n) num*=2;
    num-=3;
    //cout << num << endl;
    cout << dfs(n,x,num) << endl;
    
}