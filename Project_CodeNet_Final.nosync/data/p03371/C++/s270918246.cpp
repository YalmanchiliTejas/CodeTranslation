#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<climits>//long long型の最大値(LLONG_MAX)など
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<iterator>//集合演算(積集合,和集合,差集合など)
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm(c++17)
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<unordered_map>//イテレータあるけど順序保持しないmap
#include<unordered_set>//イテレータあるけど順序保持しないset
#include<utility>//pair
#include<vector>//可変長配列

using namespace std;
typedef long long ll;
typedef long double ld;

#define rep(i,n) for(ll i=0;i<(ll)(n);i++)


int main() {
    ll A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    ll ans1 = 0;
    ll x = min(X,Y);
    x *= 2;
    rep(i,x){
        ans1 += C;
    }

    if(X != Y){
        if(X > Y){
            rep(i,X-Y){
                ans1 += A;
            }
        }else if (Y > X){
            rep(i,Y-X){
                ans1 += B;
            }
        }
    }
    // cout << ans1 << endl;

    ll ans2 = 0;
    ans2 += A*X;
    ans2 += B*Y;
    // cout << ans2 << endl;


    ll ans3 = 0;
    ll y = max(X,Y);
    y *= 2;
    rep(i,y){
        ans3 += C;
    }
    // cout << ans3 << endl;

    cout << min(min(ans1,ans2),ans3) << endl;



}


