#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int M = 1000000007, BIG = 0x3f3f3f3f;

int n;

bool Process() {
  

  return n >= 30;
}

void Output() { cout << (Process() ? "Yes\n" : "No\n"); }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> n)
    Output();

  return 0;
}