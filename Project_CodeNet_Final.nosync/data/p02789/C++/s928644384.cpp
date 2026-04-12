#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return abs(a*b)/gcd(a,b);}
std::vector<bool> IsPrime; void sieve(size_t max){if(max+1 > IsPrime.size())IsPrime.resize(max+1,true);IsPrime[0] = false;IsPrime[1] = false;for(size_t i=2; i*i<=max; ++i)if(IsPrime[i])for(size_t j=2; i*j<=max; ++j)IsPrime[i*j] = false;}
#define roundup(divisor,dividend) (divisor + (dividend - 1)) / dividend
#define all(x) (x).begin(),(x).end()
#define size_t ll
const int mod = 1000000007;
/*
確認ポイント
cout << fixed << setprecision(n) << 小数計算//n桁の小数表記になる
vector.unique()は隣接した同じ要素を削除するので先にソートをする

計算量は変わらないが楽できるシリーズ
C++11以降でmin({a,b,c...})で複数個のmic,maxを処理できる
min(max)_element(iter,iter)で一番小さい(大きい)値のポインタが帰ってくる
count(iter,iter,int)でintがiterからiterの間にいくつあったかを取得できる

*/
int n,m;
int main(){
  cin >> n >> m;
  cout << (n == m ? "Yes":"No") << endl; 
}
