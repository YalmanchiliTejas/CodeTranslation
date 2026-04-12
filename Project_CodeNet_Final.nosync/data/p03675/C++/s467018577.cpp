#include <cstdio>
#include <vector>

int main() {
  int n;
  scanf("%d", &n);

  std::vector<int> a(n);
  for (int i=0; i<n; ++i)
    scanf("%d", &a[i]);

  std::vector<int> b;
  for (int i=n-1; i>=0; i-=2)
    b.emplace_back(a[i]);

  for (int i=n%2; i<n; i+=2)
    b.emplace_back(a[i]);

  for (int i=0; i<n; ++i)
    printf("%d%c", b[i], i+1<n? ' ':'\n');

  return 0;
}
