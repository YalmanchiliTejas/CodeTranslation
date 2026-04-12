#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define __TRUE "Yes"
#define __FALSE "No"
#define cout(x) cout << (x) << endl
#define MAX 100001
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ull> A(N);
  for(int i=0;i<N;i++) {
    cin >> A[i];
  }

  ull ans=0;
  sort(A.begin(),A.end());
  if(N%2==0){
    for(int i=N/2;i<N;i++) {
      ans += 2*A[i];
    }
    for(int i=0;i<N/2;i++) {
      ans -= 2*A[i];
    }
    ans = ans-A[N/2]+A[N/2-1];
  } else{
    ull ansYama=0;
    for(int i=N/2+1;i<N;i++) {
      ansYama += 2*A[i];
    }
    for(int i=0;i<=N/2;i++) {
      ansYama -= 2*A[i];
    }
    ansYama += (A[N/2]+A[N/2-1]);

    ull ansTani=0;
    for(int i=N/2;i<N;i++) {
      ansTani += 2*A[i];
    }
    for(int i=0;i<N/2;i++) {
      ansTani -= 2*A[i];
    }
    ansTani -= (A[N/2]+A[N/2+1]);

    ans=max(ansTani, ansYama);
  }
  cout << ans << endl;
}