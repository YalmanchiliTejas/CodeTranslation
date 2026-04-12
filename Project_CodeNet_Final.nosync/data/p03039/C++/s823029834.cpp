#include<iostream>
#include<stack>
using namespace std;

int div(int A, int B, int mod_p) {
  stack<int> q_stack;
  int a = B, b = mod_p, r;
  while (b) {
    q_stack.push(a / b);
    r = a % b; a = b; b = r;
  }
  long u = 1, v = 0;
  while (!q_stack.empty()) {
    int q = q_stack.top(); q_stack.pop();
    long u1 = v, v1 = u-q*v; u = u1 % mod_p; v = v1 % mod_p;
  }
  return (long)A * (u + mod_p) % mod_p;
}
 
int num_com(int n, int k, int mod_p) {
  int k2 = min(k, n - k);
  long nmr = 1, dnm = 1;
  for (int i = 1; i <= k2; i++) {
    nmr *= n + 1 - i; nmr %= mod_p;
    dnm *= i; dnm %= mod_p;
  }
  return div(nmr, dnm, mod_p);
}

int main() {
  int DIV = 1e+9 + 7;
  long N, M, K; cin >> N >> M >> K;
  long a = N*(N+1)*(N-1) / 6 % DIV; a = a * M * M % DIV;
  long b = M*(M+1)*(M-1) / 6 % DIV; b = b * N * N % DIV;
  int res = (a + b) * num_com(N * M - 2, K - 2, DIV) % DIV;
  cout << res << endl;
}