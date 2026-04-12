#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>bool chmin(T&a,const T&b){return a>b?(a=b,1):0;}
template<class T>bool chmax(T&a,const T&b){return a<b?(a=b,1):0;}


int nextInt() { int x; scanf("%d", &x); return x;}

int main2() {
  deque<int> b;
  int N = nextInt();
  REP(i, N) {
    int x = nextInt();
    if (i % 2 == 0) 
      b.push_back(x);
    else
      b.push_front(x);
  }
  if (N % 2 == 1) reverse(ALL(b));
  REP(i, N) {
    if (i > 0) printf(" ");
    printf("%d", b[i]);
  }
  printf("\n");
  
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws) main2();
  return 0;
}

