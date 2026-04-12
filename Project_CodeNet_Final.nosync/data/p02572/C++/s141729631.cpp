#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD 1000000007
using Graph = vector<vector<int>>;
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部が1024ビットの浮動小数点数型(TLEしたら小さくする)
using Real = mp::number<mp::cpp_dec_float<1024>>;
 
int main (){
  int N;
  cin>>N;
  vector<long long>A(N);
  rep(i,N) cin>>A[i];
  long long souwa=0;
  rep(i,N){
    souwa+=A[i];
    souwa=souwa%MOD;
  }
  long long ans=0;
  rep(i,N-1){
    souwa=(souwa-A[i]+MOD)%MOD;
    ans+=A[i]*souwa;
    ans=ans%MOD;
  }
  cout<<ans;
}