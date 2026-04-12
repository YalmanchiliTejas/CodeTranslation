/*
  #問題：
  


  #分析：
  #オブジェクト：
  
  #条件：
  

  #要求：
  

  #解法：
  
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
#include <initializer_list>
#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define uLL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;


const unsigned int BIT_FLAG_0 = (1<<0);
const unsigned int BIT_FLAG_1 = (1<<1);
const unsigned int BIT_FLAG_2 = (1<<2);
const unsigned int BIT_FLAG_3 = (1<<3);
const unsigned int BIT_FLAG_4 = (1<<4);
const unsigned int BIT_FLAG_5 = (1<<5);
const unsigned int BIT_FLAG_6 = (1<<6);
const unsigned int BIT_FLAG_7 = (1<<7);


#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
namespace mp = boost::multiprecision;

using Bint = mp::cpp_int;



int main(void){
  int n; cin>>n;
  vector<int> a(n);
  int cnt=0,max=0;
  FOR(i,0,n) {
    cin>>a[i];
    if(a[i]>=max){
      max=a[i];
      cnt++;
    }
  }
  cout<<cnt<<endl;
  return 0;
}

