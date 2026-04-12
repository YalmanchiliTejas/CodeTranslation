#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, D[300000], E[300000];

  scanf("%d", &N);
  int reach = 0;
  for(int i = 0; i < N; i++) {
    scanf("%d", &D[i]);
    E[N - i - 1] = D[i];
  }

  auto check = [&](int *A)
  {
    int reach = 0;
    for(int i = 0; i < N; i++) {
      if(reach < i * 10) return (false);
      reach = max(reach, i * 10 + A[i]);
    }
    return (true);
  };

  puts(check(D) && check(E) ? "yes" : "no");
}