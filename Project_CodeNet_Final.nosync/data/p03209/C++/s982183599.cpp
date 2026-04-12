#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
typedef long long ll;

//パテ　p0 = 1, pi = 2p(i-1)+1 pn = 2^(n+1)-1
//高さ　h0 = 1, hi = 3h(i-1)+2 hn = 2^(n+2)-3

ll rec(int n,ll x){
    if(n==0)return 1;
    ll len = (1LL<<(n+1)) - 3;//n-1レベルのバーガーの高さ
    ll num = (1LL<<n)-1;//n-1レベルのバーガーのパテ数
    if(x == 1)return 0;
    else if(x <= len+1)return rec(n-1,x-1);
    else if(x == len+2)return num+1;
    else if(x <= (len+1)*2)return num+1+rec(n-1,x-len-2);
    else return num*2+1;
}

int main(){
    int N;
    ll X;
    cin >> N >> X;
    ll ans = rec(N,X);
    cout << ans << endl;
    return 0;
}