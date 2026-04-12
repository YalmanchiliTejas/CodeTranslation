#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  
  int N;
  cin >> N;

  vector<long long> A(N);
  for(int i = 0;i < N;i++) {
    cin >> A.at(i);
  }

  sort(A.begin(),A.end());

  long long sum = 0;
  if(N%2==0) {
    for(int i = 0;i < N;i++) {
      if(i < N/2) sum -= A.at(i);
      else sum += A.at(i);
    }
    sum *= 2;
    sum += A.at((N/2)-1) - A.at(N/2);
  }else {
    long long sum2 = 0;
    int n = (N-2)/2;
    for(int i = 0;i < N;i++) {
      if(i < n+1) sum -= 2*A.at(i);
      else if(n+1 <= i && i <= n+2) sum += A.at(i);
      else sum += 2*A.at(i);
    }

    for(int i = 0;i < N;i++) {
      if(i < n) sum2 -= A.at(i);
      else if(n <= i && i <= n+1) continue;
      else sum2 += A.at(i);
    }
    sum2 *= 2;
    sum2 -= A.at(n) + A.at(n+1);
    sum = max(sum,sum2);
  }

  cout << sum << endl;
}

