#include <iostream>
#include <vector>
#include <cassert>
#include <stdio.h>

using namespace std;

int main() {

  int N;
  cin >> N;

  vector<long long> A(N+1);
  for(auto i=1; i<N+1; i++) cin>>A.at(i);

  // F[l, i], length l start at i
  vector <vector<long long> > F(  N+1 );

  F.at(1) = vector<long long>( N+1, 0);

  for(auto i = 1; i <=N; i++) {
    F.at(1).at(i) = A.at(i);
      // printf("%d %d %d\n", 1, i, F.at(1).at(i));
  }

  for (auto l=2; l <=N; l++) {

    F.at(l) = vector<long long>( N-l+2, 0 );

    for (auto i=1; i <= N - l + 1; i++) {
      auto j = i + l - 1;
      assert(j <=N);
      F.at(l).at(i) = max(
         - F.at(l-1).at(i+1) + A.at(i),
         - F.at(l-1).at(i) + A.at(j)
      );

      // printf("%d %d %d\n", l, i, F.at(l).at(i));
    }
  }
  cout << F.at(N).at(1) << endl;
  return 0;
}