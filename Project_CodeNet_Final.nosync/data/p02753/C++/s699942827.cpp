//INCLUDE
//------------------------------------------
#include <iostream>
#include <functional>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>
//DEFINE
//------------------------------------------
#define ll long long
#define ALLv(a)  (a).begin(),(a).end()
#define ALL(a,n)  (a),(a)+n
#define vi vector<long long>
#define vd vector<long double>
#define vs vector<string>
//CONST
//------------------------------------------
#define INF 1010000000000000017LL
#define MOD 1000000007LL
#define EPS 1e-12
#define PI 3.14159265358979323846
//REPEAT
//------------------------------------------
#define   FOR(i,m,n) for(ll (i)=(m);   (i)<(n);  (i)++)
#define   REP(i,n)   for(ll (i)=0;     (i)<(n);  (i)++)
#define  REPS(i,x)   for(ll (i)=1;     (i)<=(x); (i)++)
#define  RREP(i,x)   for(ll (i)=(x)-1; (i)>=0;   (i)--)
#define RREPS(i,x)   for(ll (i)=(x);   (i)> 0;   (i)--)
#define  WREP(i,in,j,jn) REP(i,in)REP(j,jn)
using namespace std;
//-------------------------------------------
int main(void){
  string S;cin>>S;
  bool flag=false;
  REP(i,S.size()-1){
    if(S[i]!=S[i+1])flag=true;
  }
  cout<<(flag?"Yes":"No")<<endl;
  return 0;
}
