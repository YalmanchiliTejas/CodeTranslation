#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define double long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define pii pair<int,int>
#define ff first
#define ss second
#define frr(i,n) for(int i=0;i<n;i++)
#define td(v) v.begin(),v.end()
#define inf 1000000000 // 1e9
#define M   1000000007 // 1e9 + 7
using namespace std;
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int lcm(int a,int b){return (a*b)/gcd(a,b);}
int exp(int a,int b,int m){
    if(b==0) return 1;
    if(b==1) return mod(a,m);
    int k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}
string s;
int d;
vector<int> v(10100);
int dp[10100][100][2];
int f(char c){
    return (c-'0');
}
int add(int a,int b){
    int ret = a + b;
    if(ret >= M) ret-= M;
    return ret;
}
int solve(int idx,int mdl,bool sml){
    int &x = dp[idx][mdl][sml];
    if(x!=-1){
        return x;
    }
    if(idx == s.size()){
        return (sml && !mdl);
    }
    x = 0;   
    int lm = f(s[idx]);
    if(sml){
        for(int i=0;i<=9;i++){
            x = add(x,solve(idx+1, (mdl + i)%d, (i <= lm))) ;
        }
    }
    else{
        for(int i=0;i<=9;i++){
            x = add(x,solve(idx+1, (mdl + i)%d, (i < lm))) ;
        }
    }
    return x;
}
int32_t main(){
    fastio;
    cin >> s >> d;
    reverse(td(s));
    ms(dp,-1);
    cout << mod(solve(0,0,1)-1,M) << endl;
}