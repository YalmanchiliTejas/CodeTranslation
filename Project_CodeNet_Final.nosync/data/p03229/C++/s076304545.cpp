#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
#define CLR(t,v) memset(t,(v),sizeof(t))
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}


int nextInt() { int x; scanf("%d", &x); return x;}
ll nextLong() { ll x; scanf("%lld", &x); return x;}


ll solve(vector<int> A) {
  const int N = A.size();
  sort(ALL(A));
  deque<int> ans;
  int l = 0, r = N-1;
  ans.push_back(A[l]);
  l++;
  while ((int)ans.size() < N) {
    int val = -1;
    int move = 0;
    if (val < abs(ans.back() - A[l])) {
      val = abs(ans.back() - A[l]);
      move = 0;
    }
    if (val < abs(ans.back() - A[r])) {
      val = abs(ans.back() - A[r]);
      move = 1;
    }
    if (val < abs(ans.front() - A[l])) {
      val = abs(ans.front() - A[l]);
      move = 2;
    }
    if (val < abs(ans.front() - A[r])) {
      val = abs(ans.front() - A[r]);
      move = 3;
    }

    if (move == 0) { ans.push_back(A[l]); l++; }
    if (move == 1) { ans.push_back(A[r]); r--; }
    if (move == 2) { ans.push_front(A[l]); l++; }
    if (move == 3) { ans.push_front(A[r]); r--; }
  }

  ll d = 0;
  for (int i = 1; i < N; i++) {
    d += abs(ans[i-1] - ans[i]);
  }
  return d;
}

int main2() {
  int N = nextInt();
  vector<int> A(N);
  REP(i, N) A[i] = nextInt();

  ll ans1 = solve(A);
  cout << ans1 << endl;

  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}