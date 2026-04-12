#include <bits/stdc++.h>
#include <typeinfo>
#include <cxxabi.h>
#ifdef LOCAL
#include "dbgtoki.hpp"
#define DUMP(i) dump((string)TOSTRING(i), demangle(typeid(i).name()), __LINE__ , i) 
#else
#define DUMP(i) 
#endif

using namespace std;
#define TOSTRING(x) #x
#define SZ(x) (int)(x).size()
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(s) (s).begin(), (s).end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()) , v.end());
#define dis distance
#define so sort
#define rev reverse
#define pub push_back


typedef long long unsigned int llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int EPS = 1e-9;
const int MOD = 1e9+7;

vi D;

bool check(){
  int jump = 0;
  REP(i,SZ(D)){
    jump = max(jump,D[i]/10);
    jump--;
    if(jump < 0){
      return false;
    }
  }
  return true;
}

int main (){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  REP(i,n){
    int a;
    cin >> a;
    D.pub(a);
  }
  int jump = 0;
  if(!check()){
    cout << "no" << endl;
    return 0;
  }
  rev(ALL(D));
  if(!check()){
    cout << "no" << endl;
    return 0;
  }
  
  cout << "yes" << endl;
  return 0;
}

