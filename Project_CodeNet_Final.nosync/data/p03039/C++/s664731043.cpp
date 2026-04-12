#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <iomanip>

using namespace std;

int mod = 1000000007;
int extgcd(int a, int b ,int &x, int&y){
  int d = a;
  if( b != 0 ){
    d = extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1,y=0;
  }
  return d;
}
int mod_inverse( int a, int m ){
  int x, y ;
  extgcd( a, m , x, y);
  return (m+x%m)%m;
}

int main(){
   long long N,M,K;
   cin >> N >> M >> K;
   long long M2= M*M;
   long long N2 =N*N;
   long long coef = 1;
   for(int i=0; i<K-2; i++){
      coef *= N*M-2-i;
      coef %= mod;
      coef *= mod_inverse(i+1,mod);
      coef %= mod;
   }
   long long D=0;
   for(int i=1; i<=N-1; i++){
      D+=(N-i)*i;
      D%=mod;
   }
   D *= M2;
   D%=mod;
   long long D2=0;
   for(int i=1; i<=M-1; i++){
      D2+=(M-i)*i;
      D2%=mod;
   }
   D2*=N2;
   D2%=mod;
   cout << ((D+D2)*coef)%mod << endl;
   
   return 0;
}
