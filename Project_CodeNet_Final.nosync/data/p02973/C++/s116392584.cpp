#include <bits/stdc++.h>
using namespace std;

int N;int big_n=2000000000;

int main() {
  cin >> N;
  vector<int> A(N);
  vector<int> B(N+1);B.at(0)=-1;
  vector<vector<int>> C(N);
  for (int i=1;i<=N;i++) {
    cin >> A.at(i-1);
    B.at(i)=big_n;
  }
  for (int i=N-1;i>=0;i--) {
    auto ir=upper_bound(B.begin(),B.end(),A.at(i));
    int d=distance(B.begin(),ir);
    B.at(d)=A.at(i);
  }
  int max_c=0;
  for (int i=0;i<=N;i++) {
    if (B.at(i)==big_n) {
      break;
    }
    max_c++;
  }
  cout << max_c-1 << endl;
}