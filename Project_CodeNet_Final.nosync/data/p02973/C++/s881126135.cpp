// E. Magical Permutation
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Kuro has just learned about permutations and he is really excited to create a
// new permutation type. He has chosen 𝑛 distinct positive integers and put all
// of them in a set 𝑆. Now he defines a magical permutation to be:

// A permutation of integers from 0 to 2𝑥−1, where 𝑥 is a non-negative integer.
// The bitwise xor of any two consecutive elements in the permutation is an
// element in 𝑆. Since Kuro is really excited about magical permutations, he
// wants to create the longest magical permutation possible. In other words, he
// wants to find the largest non-negative integer 𝑥 such that there is a magical
// permutation of integers from 0 to 2𝑥−1. Since he is a newbie in the subject,
// he wants you to help him find this value of 𝑥 and also the magical
// permutation for that 𝑥.

// Input
// The first line contains the integer 𝑛 (1≤𝑛≤2⋅105) — the number of elements in
// the set 𝑆.

// The next line contains 𝑛 distinct integers 𝑆1,𝑆2,…,𝑆𝑛 (1≤𝑆𝑖≤2⋅105) — the
// elements in the set 𝑆.

// Output
// In the first line print the largest non-negative integer 𝑥, such that there
// is a magical permutation of integers from 0 to 2𝑥−1.

// Then print 2𝑥 integers describing a magical permutation of integers from 0 to
// 2𝑥−1. If there are multiple such magical permutations, print any of them.

// Examples
// inputCopy
// 3
// 1 2 3
// outputCopy
// 2
// 0 1 3 2
// inputCopy
// 2
// 2 3
// outputCopy
// 2
// 0 2 1 3
// inputCopy
// 4
// 1 2 3 4
// outputCopy
// 3
// 0 1 3 2 6 7 5 4
// inputCopy
// 2
// 2 4
// outputCopy
// 0
// 0
// inputCopy
// 1
// 20
// outputCopy
// 0
// 0
// inputCopy
// 1
// 1
// outputCopy
// 1
// 0 1
// Note
// In the first example, 0,1,3,2 is a magical permutation since:

// 0⊕1=1∈𝑆
// 1⊕3=2∈𝑆
// 3⊕2=1∈𝑆
// Where ⊕ denotes bitwise xor operation.

#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;

int n, m, d;
int i, j, k;

vector<int> a;

int longest_increasing_sequences() {
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    auto it = upper_bound(v.begin(), v.end(), a[i]);
    if (it != v.end()) {
      *it = a[i];
    } else {
      v.push_back(a[i]);
    }
  }
  return v.size();
}

void solve() {
  cin >> n;
  a.resize(n);
  for (auto& x : a) cin >> x;
  reverse(a.begin(), a.end());
  cout << longest_increasing_sequences() << endl;
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
