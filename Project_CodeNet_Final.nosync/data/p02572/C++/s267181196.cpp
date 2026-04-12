#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
using Bint = mp::cpp_int;

int main()
{
  int N;

  cin >> N;

  vector<Bint> A(N);

  for(int i=0; i<N; ++i){
    cin >> A[i];
  }

  Bint ret1 = 0, ret2 = 0;

  for(int i=0; i<N; ++i){
    ret1 += A[i];
    ret2 += A[i]*A[i];
  }

  cout << ((ret1*ret1-ret2)/2)%1000000007 << endl;

  return 0;
}