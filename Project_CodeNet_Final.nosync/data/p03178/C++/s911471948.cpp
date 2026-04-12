#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
#define all(v) v.begin(),v.end()
#define endl "\n"
#define clr(n, r) memset(n,r,sizeof(n));

void fast() {
    cin.tie(0);
    cin.sync_with_stdio(0);
}

string b;
ll m, d, dp[10001][101][2], modu = 1e9 + 7;
ll ans(int i=0,int mod=0,bool high=0){
    if(i==b.size())return !mod;
    ll &res=dp[i][mod][high];
    if(~res)return res;
    res=0;
    for (int j = 0; j <=9 ; ++j) {
        if((!high&&j>b[i]-'0'))continue;
        res+=ans(i+1,(mod+j)%m,high||(j<b[i]-'0'))%modu;
        res%=modu;
    }
    return res;
}



int main() {
    fast();
    cin >> b>>m;
    clr(dp,-1);
    cout<<(ans()-1+modu)%modu;
}