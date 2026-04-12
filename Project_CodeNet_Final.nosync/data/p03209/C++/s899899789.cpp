#include <bits/stdc++.h>
#define int long
#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define IOS cin.tie(0); ios::sync_with_stdio(false)
using namespace std;
int gcd(int a,int b){return b ? gcd(b,a%b) : a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}

ll N,X,p[55],bp[55];
ll dfs(ll n,ll x){
    if(n==0) {if(x<=0) return 0; else return 1;}
    if(x<=bp[n-1]+1) return dfs(n-1,x-1);
    else return p[n-1]+1+dfs(n-1,x-2-bp[n-1]);
}
main() {
    cin >> N >> X;
    p[0]=1; bp[0]=1;
    for(int i=1;i<=N;i++){
        p[i]=p[i-1]*2+1;
    }
    for(int i=1;i<=N;i++){
        bp[i]=bp[i-1]*2+3;
    }
    cout << dfs(N,X) << endl;
}
