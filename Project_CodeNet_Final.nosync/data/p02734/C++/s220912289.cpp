//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/abc159/tasks/abc159_f
//数え上げのDPでは多項式を用いる方法がある

//例えば、数列{2,4,2}の部分和問題を考える
//この数列から1個以上選び出して4を作る場合の数を求める

//まず先頭の2について考えると、この2を選ぶ場合と選ばない場合について、
//+0と+2、両方の場合が考えられる
//よって2を(x^0 + x^2) = (1 + x^2)に対応させる
//4,2についても同じことをして
//{2,4,2}を
//(1 + x^2),(1 + x^4),(1 + x^2)
//に対応させる

//この全てを乗算してf(x)=(1 + x^2)(1 + x^4)(1 + x^2)とする。
//これを展開するとx^nの係数は
//数列{2,4,2}からいくつか要素を取り出して和をnに
//できるような組み合わせの個数を表す

//例えば今回はf(x) = x^8 + 2x^6 + 2x^4 + 2x^2 + 1　となるが、
//x^4　の係数は 2 となっている

//これは{2,4,2}から和を4にするような要素を選ぼうとすると
//{2,2}と{4}の二通りあることを意味する

//しかし例えば
//{2,4,2}から和を7にするような要素の組み合わせを選ぼうとしても
//そんな組み合わせは作れないのでx^7の係数は0になっている

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

const LL MOD = 998244353LL;

int N,S;
int A[3000];

LL ans = 0;

void solve(){
    vector<LL> dp(S+1,0);//多項式f(x)を格納
    //数列を前からi番目まで見た時について考える
    for(int i=0;i<N;i++){
        dp[0] += 1;// f(x) += 1
        //1 = x^0 の係数は数列から選び出したときに、和を0にできるような組の数を表す
        //f(x) *= (1+x^A[i])を実行
        vector<LL> dp_new(S+1,0);//多項式を格納
        for(int j=0;j<=S;j++){//x^jについて計算する
            dp_new[j] += dp[j];//f(x)のx^jの項の係数を持ってくる
            //その項にx^A[i]をかける
            //項の次数がSを超える→その項の係数は和がSより大きくなる組み合わせを表すが
            //今回は必要ないのでカット
            if(j+A[i]<=S){
                //x^(j+A[i])の係数にx^jの係数を足す
                dp_new[j+A[i]] += dp[j];
                dp_new[j+A[i]] %= MOD;
            }
        }
        dp = dp_new;
        ans += dp[S];
        ans %= MOD;
    }
}
 
int main(){
    cin >> N >> S;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
 
    solve();

    cout << ans << endl;
    return 0;
}