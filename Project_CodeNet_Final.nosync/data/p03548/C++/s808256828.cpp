#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
long long int lcm(long long int a,long long int b){
  long long int n;
  n=a*b/__gcd(a,b);
  return n;
}
using ll =long long int;
#define ci(a) cin>>a
#define co(a) cout<<a<<endl
#define gcd(a,b) __gcd(a,b)
#define vec vector<ll>
#define for(i,a,b) for(int i=a;i<b;i++)
#define sort(a,b) sort(a.begin(),b.end())
//gcd 最大公約数
//lcm 最小公倍数
//double 少数（変数）
//string 文字列（変数）
//sqrt 平方根
//ceil 天井関数
//floor 床関数
//abs 絶対値
//pow 累乗
//cbrt  立方根
//hypot 平方和の平方根
//(string-'0') 文字列を数字に変換
 
int main() {
  ll a,b,c;
  ci(a>>b>>c);
  ll d=b+c;
  a-=c;
  for(i,1,pow(10,5)){
    a-=d;
    if(a<d){
      co(i);
      break;
    }
  }
}