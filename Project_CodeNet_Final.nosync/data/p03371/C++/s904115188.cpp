#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
using namespace std;
typedef long long ll;

int main()
{
  int N,A,B,C,X,Y;
  int a[110000];
  int res=0;
  cin >> A>>B>>C>>X>>Y;

  if(A+B>C*2) {
    int n = min(X,Y);
    res += C*2*min(X,Y);
    X -= n;
    Y -= n;
  }
  if(A>C*2 && X>0){
    res += C*2*X;
    X = 0;
    Y = max(Y-X,0);
  }
  if(B>C*2 && Y>0){
    res += C*2*Y;
    X = max(X-Y,0);
    Y = 0;
  }

  res += A*X + B*Y;

  cout << res << endl;
}
