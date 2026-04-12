//#include <bits/stdc++.h>
//#include <stdio.h>
#include<iostream>
#include<cstdio>
#include<bitset>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<stack>
//#include <bits/stdc++.h>
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
constexpr ll lcm(int a,int b){return a*b/gcd(a,b);}
constexpr ll abs(ll a,ll b){
if(a>=b)return a-b;
if(a<b)return b-a;
}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
 

 
int main() {
    ll S;
    int ans=0;
    cin >> S;

    if(S==3||S==5||S==7){
  cout<<"YES"<<endl;
    }else{
  cout<<"NO"<<endl;
    }

  return 0;
}



