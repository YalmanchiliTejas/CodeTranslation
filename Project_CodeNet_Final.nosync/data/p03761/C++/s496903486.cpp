#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int n;
  cin >> n;
  vector<pair<int, string>> S(n); // 文字列の長さと文字列
  for (int i=0; i<n; i++) {
    cin >> S[i].second;
    S[i].first = S[i].second.size();
  }
  sort(S.begin(), S.end()); // 文字列の長さについて昇順ソート
  map<char, int> dict; // S[0]に含まれるアルファベットと登場回数
  for (int i=0; i<S[0].second.size(); i++) {
    if (dict.count(S[0].second[i])) dict[S[0].second[i]]++;
    else dict[S[0].second[i]] = 1;
  }
  for (int i=1; i<n; i++) {
    map<char, int> dict1; // S[i]に含まれるアルファベットと登場回数
    for (int j=0; j<S[i].second.size(); j++) {
      if (dict1.count(S[i].second[j])) dict1[S[i].second[j]]++;
      else dict1[S[i].second[j]] = 1;
    }
    // 登場回数が小さい方に合わせる
    for (auto p: dict) {
      auto key = p.first;
      dict[key] = min(dict[key], dict1[key]);
    }
  }
  for (auto p: dict) {
    auto key = p.first;
    auto value = p.second;
    for (int i=0; i<value; i++) cout << key;
  }
  cout << endl;
}