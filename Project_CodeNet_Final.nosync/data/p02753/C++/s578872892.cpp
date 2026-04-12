#include <cstdio>

using namespace std;
typedef long long llong;

#define MAX
const llong mod = 1000000000 + 7;

int main()
{
  char S[3];
  scanf("%s", S);
  if (S[0] == 'A' && S[1] == 'A' && S[2] == 'A')
    printf("No\n");
  else if (S[0] == 'B' && S[1] == 'B' && S[2] == 'B')
    printf("No\n");
  else
    printf("Yes");
  return 0;
}