#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
// 多倍長テンプレ
/* ---------------------- ここから ---------------------- */
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部が1024ビットの浮動小数点数型(TLEしたら小さくする)
using Real = mp::number<mp::cpp_dec_float<1024>>;
/* ---------------------- ここまで ---------------------- */
void YES(){cout << "YES" << endl;}
void NO(){cout << "NO" << endl;}
void Yes(){cout << "Yes" << endl;}
void No(){cout << "No" << endl;}
int main() {
  int N;
  cin >> N;
  long long int A[N];
  Bint sum=0;
  Bint array_sum=0;
  Bint mod=1000000007;
  for(int i=0;i<N;i++){
    cin >> A[i];
    sum+=A[i];
    array_sum+=A[i]*A[i];
  }
  sum=sum*sum;
  cout << ((sum-array_sum)/2)%mod;
  cout << endl;
  return 0;
}
