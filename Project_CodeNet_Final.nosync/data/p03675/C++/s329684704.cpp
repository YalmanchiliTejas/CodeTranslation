#include <iostream>
#include <vector>
#include <algorithm>
#define REP(i, a, n) for(int i = ((int) a); i < ((int) n); i++)
using namespace std;

int N, A;
vector<int> head, tail;

int main(void) {
  cin >> N;
  REP(i, 0, N) {
    cin >> A;
    head.push_back(A);
    swap(head, tail);
  }
  reverse(tail.begin(), tail.end());
  REP(i, 0, tail.size()) cout << tail[i] << " ";
  REP(i, 0, head.size()) cout << head[i] << " ";

  return 0;
}
