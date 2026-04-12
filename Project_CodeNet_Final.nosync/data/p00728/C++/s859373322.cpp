#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main() {
  while(true) {
    int N; cin >> N;
    if(N == 0) break;
    vector<int> score(N);
    for(int i = 0; i < N; i++)
      cin >> score[i];
    sort(score.begin(), score.end());
    cout << accumulate(&score[1], &score[N-1], 0) / (N - 2) << endl;
  }
}