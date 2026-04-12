#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int,int>;
constexpr ll mod = 1000000007;
void pPRINTl(ostream& ost) { ost << endl; }
template <class T>void pPRINTL(ostream& ost,T t){ost<<t<<endl;}
template <class T, class... U>void pPRINTl(ostream& ost, T t, U... u) {ost << t << " ";pPRINTl(ost, u...);}
template <class... T>void PRINTl(T... t) { pPRINTl(cout, t...); }
//#define PRINTl //
void pPRINT(ostream& ost) {}
template <class T>void pPRINT(ostream& ost, T t){ost<<t;}
template <class T, class... U>void pPRINT(ostream& ost, T t, U... u) {ost << t << " ";pPRINT(ost, u...);}
template <class... T>void PRINT(T... t) { pPRINT(cout, t...); }
 
#define DEBUG PRINTl("DEBUG line:",__LINE__)
//#define DEBUG 
 
int main(){
  
  ll n;
  cin>>n;
  ll a[n];
  REP(i,n)cin>>a[i];
  
  vector<int> l;
  l.push_back(a[0]);
  ll min=a[0];
  FOR(i,1,n){
    if(min>=a[i]){
      l.push_back(a[i]);
      min=a[i];
      continue;
    }
    REP(j,l.size()){
      if(l[j]<a[i]){
        l[j]=a[i];
        if(j==l.size()-1){
          min=a[i];
      	}
        break;
      }
    }
  }
  
  PRINT(l.size());
  
  return 0;
}