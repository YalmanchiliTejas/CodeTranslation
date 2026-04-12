#include <bits/stdc++.h>

using namespace std;

struct TrieNode
{
  int nxt[11];

  int exist; // ???????????\???????????¨????????????????????°???????¨?
  vector< int > accept; // ???????????????id

  TrieNode() : exist(0)
  {
    memset(nxt, -1, sizeof(nxt));
  }
};

struct Trie
{
  vector< TrieNode > nodes;
  int root;

  Trie() : root(0)
  {
    nodes.push_back(TrieNode());
  }

  virtual void direct_action(int node, int id) {}

  virtual void child_action(int node, int child, int id) {}

  void update_direct(int node, int id)
  {
    nodes[node].accept.push_back(id);
    direct_action(node, id);
  }

  void update_child(int node, int child, int id)
  {
    ++nodes[node].exist;
    child_action(node, child, id);
  }

  void add(const string &str, int str_index, int node_index, int id)
  {
    if(str_index == str.size()) {
      update_direct(node_index, id);
    } else {
      const int c = str[str_index] - '0';
      if(nodes[node_index].nxt[c] == -1) {
        nodes[node_index].nxt[c] = (int) nodes.size();
        nodes.push_back(TrieNode());
      }
      add(str, str_index + 1, nodes[node_index].nxt[c], id);
      update_child(node_index, nodes[node_index].nxt[c], id);
    }
  }

  void add(const string &str, int id)
  {
    add(str, 0, 0, id);
  }

  void add(const string &str)
  {
    add(str, nodes[0].exist);
  }

  int size()
  {
    return (nodes[0].exist);
  }

  int nodesize()
  {
    return ((int) nodes.size());
  }
};

struct Aho_Corasick : Trie
{
  static const int FAIL = 10;
  vector< int > correct;

  Aho_Corasick() : Trie() {}

  void build()
  {
    correct.resize(nodes.size());
    for(int i = 0; i < nodes.size(); i++) {
      correct[i] = (int) nodes[i].accept.size();
    }

    queue< int > que;
    for(int i = 0; i < 11; i++) {
      if(~nodes[0].nxt[i]) {
        nodes[nodes[0].nxt[i]].nxt[FAIL] = 0;
        que.emplace(nodes[0].nxt[i]);
      } else {
        nodes[0].nxt[i] = 0;
      }
    }
    while(!que.empty()) {
      TrieNode &now = nodes[que.front()];
      correct[que.front()] += correct[now.nxt[FAIL]];
      que.pop();
      for(int i = 0; i < 10; i++) {
        if(now.nxt[i] == -1) continue;
        int fail = now.nxt[FAIL];
        while(nodes[fail].nxt[i] == -1) {
          fail = nodes[fail].nxt[FAIL];
        }
        nodes[now.nxt[i]].nxt[FAIL] = nodes[fail].nxt[i];
        // auto &u = nodes[now.nxt[i]].accept;
        // auto &v = nodes[nodes[fail].nxt[i]].accept;
        // vector< int > accept;
        // set_union(begin(u), end(u), begin(v), end(v), back_inserter(accept));
        // u = accept;
        que.emplace(now.nxt[i]);
      }

    }
  }

  int match(const char &c, /*vector< int > &result,*/ int &now)
  {
    int count = 0;
    while(nodes[now].nxt[c - '0'] == -1) now = nodes[now].nxt[FAIL];
    now = nodes[now].nxt[c - '0'];
    count += correct[now];
    return (count);
  }
};

const int mod = 1e9 + 7;

string S;
int dp1[10001][501][2][2];
int dp2[10001][2];
Aho_Corasick aho;

int rec2(int idx, bool ue)
{
  if(idx >= S.size()) return (1);
  if(~dp2[idx][ue]) return (dp2[idx][ue]);
  char end = ue ? '9' : S[idx];
  int ret = 0;
  for(char i = '0'; i <= end; i++) {
    (ret += rec2(idx + 1, ue | (i != end))) %= mod;
  }
  return (dp2[idx][ue] = ret);
}

int rec(int idx, int beet, bool ue, bool zero)
{
  if(idx == S.size()) return (0);
  if(~dp1[idx][beet][ue][zero]) return (dp1[idx][beet][ue][zero]);
  char end = ue ? '9' : S[idx];
  int ret = 0;
  for(char i = '0'; i <= end; i++) {
    int curr = beet;
    int st = aho.match(i, curr);
    (ret += rec(idx + 1, curr, ue | (i != end), i != '0' | zero)) %= mod;
    if(i != '0' | zero) (ret += 1LL * st * rec2(idx + 1, ue | (i != end)) % mod) %= mod;
  }
  return (dp1[idx][beet][ue][zero] = ret);
}

int main()
{
  string A, B, C;
  cin >> A >> B >> C;

  aho.add(C);
  aho.build();

  S = B;
  memset(dp1, -1, sizeof(dp1));
  memset(dp2, -1, sizeof(dp2));
  int ret = rec(0, 0, 0, 0);
  if(A != "0") {
    for(int i = (int) A.size() - 1; i >= 0; i--) {
      if(A[i] == '0') {
        A[i] = '9';
      } else {
        A[i]--;
        break;
      }
    }
    S = A;
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    (ret += mod - rec(0, 0, 0, 0)) %= mod;
  } else {
    if(C == "0") (ret += 1) %= mod;
  }
  cout << ret << endl;
}