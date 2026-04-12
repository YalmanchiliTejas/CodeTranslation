#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
  Node(int64_t u) : v(u) {}
  int64_t v;
  shared_ptr<Node> next = nullptr;
};

vector<int64_t> MakeVec(unordered_map<int64_t, shared_ptr<Node>>& nodes, int64_t st) {
  shared_ptr<Node> st_adr = nodes[st];
  vector<int64_t> vec;
  vec.push_back(st_adr->v);
  shared_ptr<Node> cur = st_adr->next;
  while (cur != nullptr && cur != st_adr) {
    vec.push_back(cur->v);
    cur = cur->next;
  }
  return vec;
}

int main() {
  int64_t N, X, M;
  cin >> N >> X >> M;

  unordered_map<int64_t, shared_ptr<Node>> nodes;
  
  shared_ptr<Node> pre = make_shared<Node>(X);
  nodes[X] = pre;
  vector<int64_t> loop;
  int64_t sum = X;
  int64_t n = 1;
  for (; n < N; ++n) {
    int64_t cur = (pre->v * pre->v) % M;
    if (nodes.count(cur)) {
      loop = MakeVec(nodes, cur);
      break;
    }
    shared_ptr<Node> cur_node = make_shared<Node>(cur);
    pre->next = cur_node;
    pre = cur_node;
    nodes[cur] = cur_node;
    sum += cur;
  }
  if (n == N) {
    cout << sum << endl;
  } else {
    int64_t loop_sum = loop[0];
    vector<int64_t> sums(loop.size()+1, 0);
    sums[1] = loop[0];
    for (size_t i = 1, size = loop.size(); i < size; ++i) {
      sums[i+1] = sums[i] + loop[i];
      loop_sum += loop[i];
    }
    int64_t rest = N - n;
    cout << sum + loop_sum * (rest / loop.size()) + sums[rest % loop.size()] << endl;
  }
  
  return 0;
}
