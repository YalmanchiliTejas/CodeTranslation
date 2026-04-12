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
using namespace std;

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

using namespace std;

int solve(int );

int main(void){
  int N;

  while(1) {
    cin>>N;
    if(N==0) return 0;
    else solve(N);
  }
  return 0;
}

int solve(int N){
  vector<int> score(N);
  FOR(i,0,N){
    cin>>score[i];
  }
  sort( score.begin(),score.end() );

  int sum;
  FOR(i,1,N-1){
    sum += score[i];
  }
  int ans = sum/(N-2);
  cout<<ans<<endl;
  sum=0;
}

