#include <vector>
#include <cstdio>

using namespace std;

int main()
{
  int n=0;
  scanf("%d", &n);
  vector<int> v;
  for(int i=0; i<n; ++i) {
    int data=0;
    scanf("%d", &data);
    v.push_back(data);
  }
  int ans=1;
  int acc=v[0];
  for(int i=1; i<n; ++i) {
    if (v[i] >= acc) {
      acc = v[i];
      ++ans;
    }
  }
  printf("%d", ans);
  return 0;
}
