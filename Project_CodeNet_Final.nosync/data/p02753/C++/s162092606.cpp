#include<iostream>//入出力
#include<vector>//可変長配列
#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<cmath>//pow,logなど
#include<deque>//両端アクセスのキュー
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm(c++17)
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define RREP(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define REPS(i,a,b) for(ll i=(a);i<(b);i++)
#define RREPS(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define INF 1000000000000

int main(){
    string str;
    int count=0;
    cin >> str;
    REP(i,str.length()){
        if(str[i]==str[0]) count++;
    }
    if(count==str.length()) cout << "No" << endl;
    else cout << "Yes" << endl;
    
    return 0;
}