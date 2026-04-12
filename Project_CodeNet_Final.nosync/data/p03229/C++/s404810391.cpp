#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <string>
#include <math.h>
#include <numeric>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<int,int> P;
#define PB push_back
#define INF 100000000000000000

bool IsPrime(int num)
{
  if (num < 2) return false;
  else if (num == 2) return true;
  else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
  
  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2)
  {
    if (num % i == 0)
    {
      // 素数ではない
      return false;
    }
  }
  
  // 素数である
  return true;
}

/*********************************************************/
// 最大公約数（Greatest Common Divisor）を返す。
// 引数に０がある場合は０を返す。
//*********************************************************/
ll gcd( ll m, ll n )
{
  // 引数に０がある場合は０を返す
  if ( ( 0 == m ) || ( 0 == n ) )
    return 0;
  
  // ユークリッドの方法
  while( m != n )
  {
    if ( m > n ) m = m - n;
    else         n = n - m;
  }
  return m;
}//gcd

//*********************************************************
// 最小公倍数（Least Common Multiple）を返す。
// 引数に０がある場合は０を返す。
//*********************************************************
ll lcm( ll m, ll n )
{
  // 引数に０がある場合は０を返す
  if ( ( 0 == m ) || ( 0 == n ) )
    return 0;
  
  return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}//lcm

/********************************************************/

int main() {
  ll N,i,ans,ans2;
  cin >> N;
  vector<ll>A(N);
  vector<ll>ABig(N);
  vector<ll>ASmall(N);
  for(i=0;i<N;i++){
    cin >> A.at(i);
  }
  ans=0;
  ans2=0;
  sort(A.begin(),A.end());
  
  if(N%2==1){
    //Aでかパターン
    for(i=0;i<N;i++){
      if(i==0){
        ABig.at(i) = 1;
      } else if (i==N-1){
        ABig.at(i) = 1;
      }else if (i%2==1){
        ABig.at(i) = -2;
      } else {
        ABig.at(i) = 2;
      }
    }
    sort(ABig.begin(),ABig.end());
    for(i=0;i<N;i++){
      ans += A.at(i)*ABig.at(i);
    }
    
    //Aちいさパターン
    for(i=0;i<N;i++){
      if(i==0){
        ASmall.at(i) = -1;
      } else if (i==N-1){
        ASmall.at(i) = -1;
      } else if (i%2==1){
        ASmall.at(i) = 2;
      } else {
        ASmall.at(i) = -2;
      }
    }
    sort(ASmall.begin(),ASmall.end());
    
    for(i=0;i<N;i++){
      ans2 += A.at(i)*ASmall.at(i);
    }
    
    cout << max(ans,ans2) << endl;
  }
  
  if(N%2==0){
    //Aでかパターン
    for(i=0;i<N;i++){
      if(i==0){
        ABig.at(i) = 1;
      } else if (i==N-1){
        ABig.at(i) = -1;
      }else if (i%2==1){
        ABig.at(i) = -2;
      } else {
        ABig.at(i) = 2;
      }
    }
    sort(ABig.begin(),ABig.end());
    for(i=0;i<N;i++){
      ans += A.at(i)*ABig.at(i);
    }
    
    //Aちいさパターン
    for(i=0;i<N;i++){
      if(i==0){
        ASmall.at(i) = -1;
      } else if (i==N-1){
        ASmall.at(i) = 1;
      } else if (i%2==1){
        ASmall.at(i) = 2;
      } else {
        ASmall.at(i) = -2;
      }
    }
    sort(ASmall.begin(),ASmall.end());
    
    for(i=0;i<N;i++){
      ans2 += A.at(i)*ASmall.at(i);
    }
    cout << max(ans,ans2) << endl;
  }
  
  return 0;
}


