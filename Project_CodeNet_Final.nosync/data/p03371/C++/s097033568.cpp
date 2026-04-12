#include <cstdio>
#include <algorithm>
#include <vector>

int main(int argc, char *argv[])
{
  int A,B,C,X,Y;
  std::vector<int> ans;
  scanf("%d %d %d %d %d",&A,&B,&C,&X,&Y);
  ans.push_back(C * 2 * std::max(X, Y));
  ans.push_back(A * X + B * Y);
  if (X < Y) {
    ans.push_back(C * 2 * X + B * (Y - X));
  } else {
    ans.push_back(C * 2 * Y + A * (X - Y));
  }

  printf("%d\n", *std::min_element(ans.begin(), ans.end()));
  return 0;
}