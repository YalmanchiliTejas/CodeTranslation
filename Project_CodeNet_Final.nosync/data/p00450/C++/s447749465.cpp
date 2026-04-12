#include <bits/stdc++.h>
using namespace std;
#define Rep(i,N) for(int i = 0; i < N; i++)
#define INF 1 << 28
typedef pair<int,int> Pi;
#define F first
#define S second
#define pb push_back

inline void chmax(int &a, int b) { a = max(a,b); }
inline void chmin(int &a, int b) { a = min(a,b); }

int main()
{
  int N;
  while(cin >> N,N) {
    stack<Pi>st;
    int A;
    int sum = 0;
    Rep(i,N) {
      cin >> A;
      if(!A)sum++;
      if(!(i & 1) || st.top().F == A) {
	if(st.empty() || st.top().F != A)st.push(Pi(A,i));
	continue;
      }
      int p = st.top().S;
      st.pop();
      if(A)sum -= (i - p);
      else sum += (i - p);
      if(st.empty())st.push(Pi(A,0));
    }
    cout << sum << endl;
  }
  return 0;
}