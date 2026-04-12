//include
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath> 
#include <iomanip>
#include <math.h>
#include <utility>
#include <functional>
#include <cstdlib>
#include <map>
#include <utility>
//using
using namespace std;
using vl = vector <long long>;
using vs = vector <string>;
using vc = vector <char>;
using ll= long long;
using vvl = vector<vector<ll> >;
using vvc = vector<vector<char> >;
//vector<vector<char> > hyou(N, vector<char>(N));
using vd = vector <double>;
//define
//#define int long long
#define rep(i,n) for(int i=0; i<n; i++)
#define print(n) cout<<n<<endl;
#define sortp(d) sort(d.begin(),d.end()) //1234
#define sortm(d) sort(d.rbegin(),d.rend()) //4321
//素数判定　O(√A) 
bool is_prime(int x){
 if(x<=1) return false;
 for(int i=2;i*i<=x;i++)
 if(x%i==0) return false;
 return true;
 }
 //各位の和　
int wa(ll x)
{
ll sum = 0;
while(x!=0){
  sum += x% 10;
  x /= 10;
}
return sum;
}
/*順列生成
do {
  // 順列に対する処理
} while (next_permutation(配列変数.begin(), 配列変数.end()));*/

//絶対値　abs()
//文字→数字　'0' アルファベット→数字　'a'　'A'が65番,'a'が97番だわ
//型キャスト　char('a'+1)
//reverse 回文
//if(isupper('A'))->大なら真


//グローバル変数宣言
ll p=0,q=0,r=0,s;

int main()
{
  ll a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  c*=2;
  s=5000000000;
  rep(i,100001)
  {
    p=x-i;
    q=y-i;
    if(p<0)p=0;
    if(q<0)q=0;
    r=c*i+a*p+b*q;
    s=min(s,r);
  }
  print(s)
}