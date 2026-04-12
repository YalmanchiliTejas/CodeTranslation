#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <numeric>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <sstream>

using namespace std;
typedef long long ll;

//マクロ
//forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//xにはvectorなどのコンテナ
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
//定数
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)
#define PI 3.14159265359 //πの値
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define C(x) cout << x << endl //テスト出力

//関数
//nCkの計算の関数(呼び出しは[cbn])
ll cbn(ll n, ll k) {
    ll r = 1;
    for (ll d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}
// a^n mod を計算する
ll powmod(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}
//２つの最大公約数
int gcb(int a, int b){
    if(a < b){
        int x = a;
        a = b;
        b = x;
    }
    int amari = a % b;
    if(amari == 0) return b;

    return gcb(b, amari);
}
//３つの最大公約数
int gcb_3(int a, int b, int c){
    return gcb(gcb(a, b), c);
}

/*map<Keyの型, Valueの型> 変数名;
queue<型> 変数名;
priority_queue<型> 変数名;
priority_queue<型, vector<型>, greater<型>> 変数名;
vector<vector<要素の型>> 変数名(要素数1, vector<要素の型>(要素数2, 初期値))*/

/*-----------------------------ここから-----------------------------*/

int main() {
cin.tie(0);
ios::sync_with_stdio(false);
ll n; cin>>n;
vector<ll> data(n);
REP(i,n) cin>>data[i];
ll cnt = 0;
ll max_height = 0;
REP(i,n) {
  max_height = max(max_height,data[i]);
  if(data[i]>=max_height) cnt++;
}
  cout<<cnt;
}