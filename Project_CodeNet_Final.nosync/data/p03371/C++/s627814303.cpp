#include<bits/stdc++.h>
using namespace std;

using ll=long long;

const int MAX = 2200000;
const long long MOD = 1000000007;
long long INF = 90000000001000;

long long fac[MAX], finv[MAX], inv[MAX];

unsigned GetDigit(unsigned num){
    return to_string(num).length();
}

vector<ll> enumDivisor(ll n){
    vector<ll> res;
    for(ll i=1; i*i<=n; ++i){//nの二乗根まで調べれば良い。
        if(n%i != 0) continue;//割り切れない場合
        res.push_back(i);//割り切れたらresにいれる
        if(i*i != n) res.push_back(n/i);//二乗根じゃない場合もう片方の約数もいれる。
    }
    return res;
}


int main() {
int a,b,c,x,y,mx;
ll ans=INF;
cin >> a >> b >> c >> x >> y;
mx = max(x,y);
for (int i = 0; i <= mx; ++i)
{
    int an,bn;
    ll sum = 0;
    an = max(0,x-i);bn = max(0,y-i);
    sum = an*a+bn*b+i*2*c;
    ans = min(ans,sum);
}

cout << ans;
return 0;
}


