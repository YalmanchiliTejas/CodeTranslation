#include <bits/stdc++.h>
#include <stdio.h>
#include<iostream>
#include<cstdio>
#include<bitset>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<string.h>
#include<cmath>
#include<utility>
#include<functional>
#include<map>
#include<set>
#include<cctype>
#include<fstream>
#include <numeric>
#include <iomanip>
#include <cstring> 
using namespace std;
using ll=long long;

#define FOR(i, a, b) for( int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for( int i=(a);i>=(b);i--)
#define LFOR(i, a, b) for( long long int i=(a);i<=(b);i++)
#define LRFOR(i, a, b) for(long long int i=(a);i>=(b);i--)
#define MOD 1000000007
#define LLONG_MAXs 9223372036854775800

#include <iostream>
#include <cmath>
using namespace std;
 

 
bool isPrimeNum( ll x ){ // 素数である場合 true を返す
  if( x <= 1 ){ // 1以下である場合は素数でないことがすぐにわかる
    return false;
  }
  // sqrt( double型 ) は引数の平方根を double型で返すので、int型でキャスト
  int n = (int)sqrt( (double)x );
  for( int i = 2; i <= n; i++ ){
    if( x % i == 0 ){ // 割り切る整数がある場合、即判定終了
      return false;
    }
  }
  return true; // 割り切る整数がない場合、素数である
}

constexpr ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
constexpr ll lcm(ll a,ll b){return a*b/gcd(a,b);}
constexpr ll abs(ll a,ll b){
if(a>=b)return a-b;
if(a<b)return b-a;
}
constexpr ll min(ll a,ll b){
if(a>=b)return b;
if(a<b)return a;
}

constexpr ll max(ll a,ll b){
if(a>=b)return a;
if(a<b)return b;
}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int main() {
  ll N,M;

  cin>>N>>M;
  ll a[N][N];
  ll ans =0;
  ll tempa,tempb;
  FOR(i,0,N-1){
    FOR(j,0,N-1){
      a[i][j]=0;
      
    }
  }
  FOR(i,0,M-1){
    cin>>tempa>>tempb;
    a[tempa-1][tempb-1]=1;
    a[tempb-1][tempa-1]=1;
  }
  FOR(i,0,N-1){
    FOR(j,0,N-1){
     // cout<<a[i][j];
      
    }
      //cout<<endl;
  }

  vector<ll> v(N);
  iota(v.begin(), v.end(), 1);       // v に 1, 2, ... N を設定
  do {
      ll flag=0;
      if(v[0]!=1){
        flag=1;
      }
      FOR(i,0,N-2){
        if(a[v[i]-1][v[i+1]-1]!=1){
          flag=1;
          break;
        }
      }
      if(flag!=1){
        ans++;
      }
      //for(auto x : v) cout << x << " "; cout  <<" "<<flag<<"\n";
  } while( next_permutation(v.begin(), v.end()) );     // 次の順列を生成





  cout<<ans<<endl;
  return 0;


 
}
 
