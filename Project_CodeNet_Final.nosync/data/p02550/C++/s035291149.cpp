#include<iostream>
#include<vector>
using namespace std;
int main() {
  long long N;
  int X,M;
  cin >> N >> X >> M;
  vector<long long> p(M,-1),A(M+3);
  A[0] = X;
  int i = 0,j;
  bool f = true;
  while(f) {
    i++;
    A[i] = (A[i-1]*A[i-1])%M;
    if(p[A[i]] > 0)f = false;
    else p[A[i]] = i;
  }
  long long ans = X;
  if(p[A[i]] < N)for(j=0;j<M;j++) {
    if(p[j] >= p[A[i]] && p[j] < i)ans += (N-p[A[i]])/(i-p[A[i]])*j;
    if(p[j] >= p[A[i]] && p[j] <= p[A[i]] + (N-p[A[i]])%(i-p[A[i]]) - 1)ans += j;
  }
  for(j=0;j<M;j++)if(p[j] > 0 && p[j] < min(p[A[i]],N))ans += j;
  cout << ans << endl;
}