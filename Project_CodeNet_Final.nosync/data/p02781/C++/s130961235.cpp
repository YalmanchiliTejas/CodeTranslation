#include <bits/stdc++.h>

#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9+7;
const ll LINF = 1LL << 60;
const int INF = 1e9 + 7;

string s;
int n, k;

//組み合わせの計算
const ll MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];
//初期化
void COMinit() {
    fac[0]  = fac[1]  = 1;
    finv[0] = finv[1] = 1;
    inv[1]  = 1;

    for(int i = 2; i < MAX; ++i){
        fac[i]  = fac[i - 1] * i % MOD;
        inv[i]  = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
//nCk
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;

    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll calc(int digit, int keta, bool issmall){
    if(digit == n){
        //０でない数字が０個欲しい場合は１つ存在する
        if(keta == 0)return 1;
        else return 0;
    }
    //０でない数字が０個欲しい場合は１つ存在する
    if(keta == 0)return 1;

    //今ある桁以下で全部１〜９まで使えるなら、nCk*9^k個存在する
    if(issmall)return COM(n-digit, keta) * pow(9, keta);
    else {
        //0の場合は何もしない
        if(s[digit] == '0') return calc(digit+1, keta, false);
        else{
            //今の桁は0、なので必ずsより小さくなる
            ll zero = calc(digit+1, keta, true);
            //今の桁の数を1つ減して０でない数に、これは桁の数−１個ぶんある
            ll reduce = calc(digit+1, keta-1, true) * (s[digit]-'1');
            //今の桁をそのまま使う
            ll stay = calc(digit+1, keta-1, false);

            return zero + reduce + stay;

        }
    }
}

int main(){
    cin >> s >> k;
    n = s.size();

    COMinit();

    ll ans = calc(0, k, false);

    cout << ans << endl;
}