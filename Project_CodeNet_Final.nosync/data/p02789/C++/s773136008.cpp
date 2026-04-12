#if 0

#endif

#include <bits/stdc++.h>
#define REP(i, n) for(int i=0;i<int(n);++i)
using namespace std;
template<class A>void p(A a){cout << (a) << endl;}
template<class A,class B>void p(A a,B b){cout << a << " "  ;p(b);}
template<class A,class B,class C>void p(A a,B b,C c){cout << a << " " ;p(b,c);}
template<class A,class B,class C,class D>void p(A a,B b,C c,D d){cout << a << " " ;p(b,c,d);}
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
int INF=numeric_limits<int>::max();
// for copy
// for(int i=0;i<N;++i) {

int main(void) {
  int n,m;cin>>n>>m;
  if(n==m) p("Yes");
  else p("No");
  return 0;
}

